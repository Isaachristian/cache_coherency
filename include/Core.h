//
// Created by Isaac on 10/26/24.
//

#ifndef CORE_H
#define CORE_H

#include <enums/BusAction.h>
#include <enums/CCProtocol.h>
#include <enums/MemoryAction.h>
#include <enums/State.h>

class Core {
private:
	int coreNumber;

	CCProtocol protocol;
	State state = None;

public:
	int runs = 0;
	int snoops = 0;

	Core(int coreNumber, CCProtocol protocol);

	[[nodiscard]] int getCoreNumber() const;
	[[nodiscard]] State getState() const;

	BusAction run(MemoryAction action);
	BusAction snoop(BusAction action);
};

#endif // CORE_H
