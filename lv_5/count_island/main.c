#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

void uts(char **arr, int s_y, int s_x, char c, int x, int y) {
   if (s_y < y && s_x < x && s_y >= 0 && s_x >= 0) {
	   if (arr[s_y][s_x] == 'X') {
		   arr[s_y][s_x] = c;
		   uts(arr, s_y, s_x + 1, c, x, y);
		   uts(arr, s_y, s_x - 1, c, x, y);
		   uts(arr, s_y + 1, s_x, c, x, y);
		   uts(arr, s_y - 1, s_x, c, x, y);
	   }
   }
}

void flood(char **arr, int y, int x) {
	int val = 0;
	for (int j = 0; j < y; j++) {
		for (int k = 0; k < x; k++) {
			if (arr[j][k] == 'X') {
				uts(arr, j, k, val + '0', x, y);
				val++;
			}
		}
	}
}

int ct(char *name) {
	int fd = open(name, O_RDONLY);
	if (fd < 0)
		return 0;
	char buf[1024];
	for (int i = 0; i < 1024; i++)
		buf[i] = 0;
	int y = 0;
	int x = 0;
	char **arr = (char **)malloc(sizeof(char *) * 1024);
	int ct = read(fd, buf, 1024);
	if (ct < 0)
		return 0;
	for (int i = 0; i < ct; i++) {
		if (buf[i] == '\n') {
			x = i;
			break;
		}
	}
	for (int i = 0; i < 1024; i++)
		arr[i] = (char *)malloc(sizeof(char) * x);
	int i = 0;
	while (1) {
		if (ct == 0) {
			ct = read(fd, buf, 1024);
			if (ct < 0)
				return 0;
			if (ct == 0)
				break;
		}
		for (int k = 0; k < ct; k++) {
			if (buf[k] == '\n') {
				y++;
				if (i != x) {
					return 0;
				}
				i = 0;
			}
			else if (buf[k] != 'X' && buf[k] != '.') {
				return 0;
			}
			else {
				arr[y][i] = buf[k];
				i++;
			}
		}
		ct = 0;
	}
	flood(arr, y, x);
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			write(1, arr[i] + j, 1);
		}
		write(1, "\n", 1);
	}
	close(fd);
	return 1;
}

int main(int argc, char **argv) {
	if (argc == 2) {
		if (ct(argv[1]) == 0)
			write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
}
