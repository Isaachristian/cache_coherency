//
// Created by Isaac on 10/26/24.
//

#include <enums/CCProtocol.h>
#include <iostream>


#include "Core.h"

Core::Core(int coreNumber, CCProtocol protocol) : coreNumber(coreNumber), protocol(protocol) {}

int Core::getCoreNumber() const { return coreNumber; }

State Core::getState() const { return state; }

BusAction Core::run(MemoryAction action) {
	runs++;

	return NoOp;
}

BusAction Core::snoop(BusAction action) {
	snoops++;
	return NoOp;
}
