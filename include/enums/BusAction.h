//
// Created by Isaac on 10/27/24.
//

#ifndef BUSACTION_H
#define BUSACTION_H

enum BusAction {
	Read,
	ReadX,
	Upgrade,
	Flush,
	FlushOpt,
	NoOp,
};

inline std::string busActionToString(BusAction ba) {
	switch (ba) {
	case Read:
		return "Read";
	case ReadX:
		return "ReadX";
	case Upgrade:
		return "Upgrade";
	case Flush:
		return "Flush";
	case FlushOpt:
		return "FlushOpt";
	case NoOp:
		return "-";
	}
}

#endif // BUSACTION_H
