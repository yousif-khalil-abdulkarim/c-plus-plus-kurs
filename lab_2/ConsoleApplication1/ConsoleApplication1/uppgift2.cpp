#include <string>

void substitute_str(
	std::string& iostring,
	const std::string& before,
	const std::string& after
) {
	int i = 0;
	while (true) {
		int start = iostring.find(before, i);
		if (start == -1) {
			break;
		}
		iostring.replace(start, before.length(), after);
		i = start + after.length();
	}
}
