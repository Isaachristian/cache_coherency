//
// Created by Isaac on 10/27/24.
//

#ifndef MEMORYACTION_H
#define MEMORYACTION_H

enum MemoryAction { READ, WRITE, EVICT };

inline std::string memoryActionToString(MemoryAction a) {
	switch (a) {
	case READ:
		return "R";
	case WRITE:
		return "W";
	case EVICT:
		return "E";
	default:
		return "?";
	}
}

#endif // MEMORYACTION_H
