#include <iostream>
#include "Storage.h"
#include "Service.h"


int main() {
	Storage st{};
	Service se{ st };

	Status cur = se.set("zhiraslan", "shedzhem");
	std::cout << static_cast<int>(cur) << std::endl;

	cur = se.set("", "shedzhem");
	std::cout << static_cast<int>(cur) << std::endl;

	cur = se.set("dina", "shedzhem");
	std::cout << static_cast<int>(cur) << std::endl;

	auto result = se.get("zhiraslan");
	if (result.ok()) {
		std::cout << "Value: " << result.val() << "\n"; // успешный get
	}
	else {
		std::cout << "Get failed: " << static_cast<int>(result.status()) << "\n"; // ошибка
	}

	result = se.get("");
	if (result.ok()) {
		std::cout << "Value: " << result.val() << "\n"; // успешный get
	}
	else {
		std::cout << "Get failed: " << static_cast<int>(result.status()) << "\n"; // ошибка
	}
}