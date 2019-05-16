#include "t_point.h"

void uts(char **tab, t_point size, t_point begin, char c) {
	if (begin.x < size.x && begin.x >= 0 && begin.y < size.y && begin.y >= 0) {
		if (tab[begin.y][begin.x] == c) {
			tab[begin.y][begin.x] = 'F';
			uts(tab, size, (t_point){begin.x + 1, begin.y}, c);
			uts(tab, size, (t_point){begin.x - 1, begin.y}, c);
			uts(tab, size, (t_point){begin.x, begin.y + 1}, c);
			uts(tab, size, (t_point){begin.x, begin.y - 1}, c);
		}
	}
}

void flood_fill(char **tab, t_point size, t_point begin) {
	if (begin.x < size.x && begin.x >= 0 && begin.y < size.y && begin.y >= 0) {
		char c = tab[begin.y][begin.x];
		uts(tab, size, begin, c);
	}
}
