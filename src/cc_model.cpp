#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#include "Core.h"
#include "enums/CCProtocol.h"
#include "enums/MemoryAction.h"
#include "structs/Input.h"

CCProtocol getProtocol(std::string protocol) {
	std::string _protocol = std::move(protocol);
	std::transform(_protocol.begin(), _protocol.end(), _protocol.begin(), ::tolower);

	if (_protocol == "msi")
		return MSI;
	if (_protocol == "mesi")
		return MESI;

	throw std::invalid_argument("Invalid protocol name!");
}

Input parseInput(const std::string &input) {
	if (input.length() != 2)
		throw std::invalid_argument("Invalid input!");

	int core = std::stoi(input.substr(1, 1));

	std::string command = input.substr(0, 1);
	std::transform(command.begin(), command.end(), command.begin(), ::tolower);

	MemoryAction action = READ;
	if (command == "r")
		action = READ;
	else if (command == "w")
		action = WRITE;
	else if (command == "e")
		action = EVICT;

	return {action, core};
}

bool prompt(std::vector<Core> &cores) {
	std::string input;

	std::cout << "Enter command: ";
	std::cin >> input;

	if (input == "q")
		return false;

	try {
		auto [action, core] = parseInput(input);
		const auto it = std::find_if(cores.begin(), cores.end(),
																 [core](const Core &c) { return c.getCoreNumber() == core; });

		// make sure a core was found
		if (it == cores.end()) {
			std::cout << input << " is not a valid core number!\n";
			return true;
		}

		Core &useCore = *it;

		const auto busAction = useCore.run(action);

		for (auto &c : cores)
			if (c.getCoreNumber() != core && busAction != NoOp)
				c.snoop(busAction);

		std::cout << memoryActionToString(action) << useCore.getCoreNumber() << " ";
		for (auto &c : cores)
			std::cout << stateToString(c.getState()) << " ";

		std::cout << busActionToString(busAction) << std::endl;
	} catch (std::invalid_argument &e) {
		std::cerr << "Error: input must be length 2 with command followed by processor number (e.g., "
								 "W1 or R2)"
							<< std::endl;
	}

	return true;
}

void run(CCProtocol protocol, int processorCount) {
	// instantiate processor count of processors
	std::vector<Core> cores;
	for (int i = 0; i < processorCount; i++) {
		cores.emplace_back(i + 1, protocol);
	}

	// run until done
	while (prompt(cores)) {
	}

	// for (const auto &core : cores)
	// std::cout << core.getCoreNumber() << ": " << core.snoops << " snoops" << std::endl;
}

int main(int argc, char *argv[]) {
	CCProtocol protocol =
			argc > 1 ? getProtocol(argv[1]) : throw std::invalid_argument("Protocol required!");
	int processorCount = argc > 2 ? atoi(argv[2]) : 1;

	run(protocol, processorCount);

	return 0;
}
