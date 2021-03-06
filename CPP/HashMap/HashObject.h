#include <string>

#ifndef HASH_OBJECT_H
#define HASH_OBJECT_H

namespace vikas {

	class HashObject {
		public:
			HashObject();
			~HashObject();
			HashObject(const HashObject &) = delete;
			HashObject &operator=(const HashObject &) = default;

			std::string &GetKey() { return key_; }
			std::string &GetValue() { return value_; }

			void SetAsDummy() {
			    key_ = GetDummyKey();
			    value_ = "";
			}

			void SetKey(const std::string key) { key_ = key; }
			void SetValue(const std::string value) { value_ = value; }
			static const std::string GetDummyKey() { return "<Dummy>"; }
			static const std::string GetNullKey() { return "<Null>"; }

		private:
			std::string key_;
			std::string value_;
	};
}

#endif