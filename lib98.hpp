/*
* LICENSE BSD-3 Clause
* DEV BY KUMAMIEE
* Header only library!
* C++ 98 compatible!
* Backporting C++11 (and later) libraries to C++98 (minimal)
* UNUSED AI
*/
#ifndef LIB98_HPP_DEV_KUMAMIEE
#define LIB98_HPP_DEV_KUMAMIEE

#include <cstddef>
#include <cstring>
#include <string>
#include <stdexcept>
#include <exception>
#include <algorithm>

namespace lib98 {
    typedef unsigned char uint8_t; //Please modify this to suit your environment.
    class string_view {
        private:
        const char *msgptr_;
        std::size_t strlength_;
        public:
        string_view() : msgptr_(NULL), strlength_(0) {}
        string_view(const char *s) : msgptr_(NULL), strlength_(0) {
            if (s) {
                msgptr_ = s;
                strlength_ = std::strlen(msgptr_);
            }
        }
        string_view(const std::string& str) {
            msgptr_ = str.c_str();
            strlength_ = str.length();
        }

        bool operator==(const string_view& other) const {
            if (strlength_ != other.strlength_) return false;
            if (msgptr_ == other.msgptr_) return true;
            if (!msgptr_ || !other.msgptr_) return false;
            return std::memcmp(msgptr_, other.msgptr_, strlength_) == 0;
        }
        bool operator!=(const string_view& other) const {
            return !(*this == other);
        }
        const char& operator[](std::size_t index) const {
            return msgptr_[index];
        }
        /*charptr return*/
        const char* c_str() const {return msgptr_;}
        std::size_t length() const {return strlength_;}
        bool empty() const {return strlength_ == 0;}
        const char* begin() const {return msgptr_;}
        const char* end() const {return msgptr_ + strlength_;}
    };
    template <typename T, std::size_t N>
    class array {
        private:
        T arraydata[N];
        public:
        array() {}
        array(const array& other) {
            std::copy(other.arraydata, other.arraydata + N, arraydata);
        }
        array& operator=(const array& other) {
            if (this == &other) return *this;
            std::copy(other.arraydata, other.arraydata + N, arraydata);
            return *this;
        }
        const T& operator[](std::size_t index) const {
            return arraydata[index];
        }
        T& operator[](std::size_t index) {
            return arraydata[index];
        }
        const T *data() const {return arraydata;}
        std::size_t size() const {return N;}
        typedef T* iterator;
        typedef const T* const_iterator;
        const T* begin() const {return arraydata;}
        T* begin() {return arraydata;}
        const T* end() const {return arraydata + N;}
        T* end() {return arraydata + N;}
        const T& at(std::size_t index) const {
            if (index >= N) {
                throw std::out_of_range("array: out array index.");
            } else {
                return arraydata[index];
            }
        }
        T& at(std::size_t index) {
            if (index >= N) {
                throw std::out_of_range("array: out array index.");
            } else {
                return arraydata[index];
            }
        }
    };
    class bytesarr {
        private:
        uint8_t* buf;
        std::size_t size;
        bool inited;
        public:
        bytesarr() : inited(false) {}
        bytesarr(const std::size_t arrsize) : size(arrsize), inited(true) {
            buf = new uint8_t[size];
        }
        bytesarr(const bytesarr& other) : inited(true), size(other.size) {
            buf = new uint8_t[size];
            std::copy(other.buf, other.buf + other.size, buf);
        }
        bytesarr& operator=(const bytesarr& other) {
            if (this == &other) return *this;
            delete[] buf;
            size = other.size;
            buf = new uint8_t[size];
            std::copy(other.buf, other.buf + other.size, buf);
            return *this;
        }
        const uint8_t& operator[](std::size_t index) const {
            return buf[index];
        }
        uint8_t& operator[](std::size_t index) {
            return buf[index];
        }
        ~bytesarr() {
            if (inited) delete[] buf;
        }
        const uint8_t* data() const {return buf;}
        const std::size_t bufsize() const {return size;}
        typedef uint8_t* iterator;
        typedef const uint8_t* const_iterator;
        const uint8_t* begin() const {return buf;}
        uint8_t* begin() {return buf;}
        const uint8_t* end() const {return buf + size;}
        uint8_t* end() {return buf + size;}
        void init(const std::size_t n) {
            if (inited) {
                return;
            }
            size = n;
            buf = new uint8_t[size];
            inited = true;
        }
    };
    class over_size : public std::exception {
        private:
        const char* message_;
        public:
        explicit over_size(const char* msg) : message_(msg) {}
        virtual ~over_size() throw() {}
        virtual const char* what() const throw() {
            return message_;
        }
    };
} //namespace lib98
#endif