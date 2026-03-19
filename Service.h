#pragma once

#include <cassert>
#include "Storage.h"


enum class Status {
	OK,
	NOT_FOUND,
	INVALID_KEY
};


template<typename T>
class Result {
public:
	// конструктор дл€ ќ 
	Result(const T& value)
		: value_{ value }, status_{ Status::OK }, isOk_{true} {}

	// конструктор дл€ ошибки
	Result(Status status)
		: status_{status}, isOk_{ false} {}

	bool ok() const {
		return isOk_;
	}

	const T& value() const{
		assert(ok());
		
		//if (!ok()) {
		//	std::terminate();
		//}
		return value_;
	}

	Status status() const {
		return status_;
	}

private:
	T value_{};
	Status status_{ Status::OK };
	bool isOk_{ false };
};


class Service
{
public:
	explicit Service(Storage& storage);

	Status set(const std::string& key, const std::string& val);

	Result<std::string> get(const std::string& key) const;

	Status del(const std::string& key);
private:
	static const size_t MAX_KEY_SIZE = 256;

	bool isKeyValid(const std::string& key) const;

	// Storage должен жить дольше Service, иначе будет вис€ча€ ссылка.
	// ≈сли по€витс€ сомнение, можно использовать std::shared_ptr<Storage> дл€ безопасного хранени€.
	Storage& storage_; 
};