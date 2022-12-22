#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	string a, b;
	cin >> a >> b;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	const auto& l1 = a.length();
	const auto& l2 = b.length();

	auto oss = ostringstream{};
	auto c = int{ 0 };
	auto j = int{ 0 };
	for (auto i = 0; i < l1 && i < l2; ++i) {
		auto b1 = ('1' == a[i]) ? 1 : 0;
		auto b2 = ('1' == b[i]) ? 1 : 0;

		auto b3 = b1 + b2 + c;
		if (1 < b3) {
			c = 1;
		}
		else {
			c = 0;
		}

		oss << b3 % 2;

		++j;
	}

	if (l1 < l2) {
		for (auto k = j; k < l2; ++k) {
			auto b2 = ('1' == b[k]) ? 1 : 0;

			auto b3 = b2 + c;
			if (1 < b3) {
				c = 1;
			}
			else {
				c = 0;
			}

			oss << b3 % 2;
		}
	}
	else if (l2 < l1) {
		for (auto k = j; k < l1; ++k) {
			auto b1 = ('1' == a[k]) ? 1 : 0;

			auto b3 = b1 + c;
			if (1 < b3) {
				c = 1;
			}
			else {
				c = 0;
			}

			oss << b3 % 2;
		}
	}

	if (1 == c) {
		oss << 1;
	}

	auto ans = static_cast<string>(oss.str());
	reverse(ans.begin(), ans.end());
	ans.erase(0, ans.find_first_not_of('0'));
	if (0 == ans.length()) {
		ans = "0";
	}
	cout << ans;

	return 0;
}