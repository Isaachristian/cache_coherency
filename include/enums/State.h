//
// Created by Isaac on 10/27/24.
//

#ifndef STATE_H
#define STATE_H

enum State { None, M, E, S, I, O, F };

inline std::string stateToString(State s) {
	switch (s) {
	case None:
		return "-";
	case M:
		return "M";
	case E:
		return "E";
	case S:
		return "S";
	case I:
		return "I";
	case O:
		return "O";
	case F:
		return "F";
	}
}

#endif // STATE_H
