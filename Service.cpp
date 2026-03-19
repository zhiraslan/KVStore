#include "Service.h"

explicit Service::Service(Storage& storage)
	: storage_{ storage };

Status Service::set() {

}

Result<std::string> Service::get(const std::string& key) const {

}

Status Service : del() {

}

bool Service::isKeyValid(const std::string& key) const {
	return !key.empty() && MAX_KEY_SIZE <= 256;
}