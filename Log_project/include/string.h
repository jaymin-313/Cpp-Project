
#include"exception.h"
#include <iostream> 
#include <cstring> 
#include<memory>
#ifndef STRING_H
#define STRING_H


namespace utility {
    class String {
    private:
        std::unique_ptr<char[]> m_Buffer{nullptr};
        size_t m_Size{ 0 };

    public:
        String(const char* string="") {
            //std::cout << "Default constructor Called" << std::endl;
            m_Size = strlen(string);

            m_Buffer = std::make_unique<char[]>(m_Size + 1);
            memcpy(m_Buffer.get(), string, m_Size);
            m_Buffer[m_Size] = 0;
           //print();
        }
        

        String(const String& string) {
           // std::cout << "Copy Constructor called" << std::endl;
            m_Size = string.m_Size;
           
            m_Buffer = std::make_unique<char[]>(m_Size + 1);

            memcpy(m_Buffer.get(), string.m_Buffer.get(), m_Size);
            m_Buffer[m_Size] = 0;
           // return m_Buffer;
        }
        String& operator=(const String& string) {
           // std::cout << "Copy Assignment called" << std::endl;
            if (this != &string) {
                //delete[]m_Buffer;
                m_Size = string.m_Size;
               m_Buffer = std::make_unique<char[]>(m_Size + 1);
                memcpy(m_Buffer.get(), string.m_Buffer.get(), m_Size);
                m_Buffer[m_Size] = 0;
            }

            return *this;

        }
        String& operator+(const String& string) {
            if (string.m_Size != 0) {
                size_t newSize = m_Size + string.m_Size;
                std::unique_ptr<char[]> result = std::make_unique<char[]>(newSize + 1);
                memcpy(result.get(), m_Buffer.get(), m_Size);
                memcpy(result.get() + m_Size, string.m_Buffer.get(), string.m_Size + 1);

                m_Size = newSize;
                m_Buffer = std::move(result);

            }
            return *this;
        }
        String(String&& string)  noexcept {
           // std::cout << "Move Constructor called" << std::endl;
            m_Buffer = std::move(string.m_Buffer);
            m_Size = string.m_Size;
            string.m_Buffer = nullptr;
            string.m_Size = 0;
        }
        String& operator=(String&& string) noexcept {
            //std::cout << "Move Assignment called" << std::endl;
            if (this != &string) {
               // delete[] m_Buffer;
                m_Size = string.m_Size;
                m_Buffer = std::move(string.m_Buffer);
                string.m_Buffer = nullptr;
                string.m_Size = 0;

            }
            return *this;
        }
        char* getCharString();

        char operator[](int) ;
        void getlength() const ;
        void tolowercase();
        void touppercase();
        void print() const;
        void concatenate(const String&);
        static String intToString(int);
        void flush();
        ~String() {
            //delete[] m_Buffer;
        }
        friend std::ostream& operator<<(std::ostream& stream, const String&
            string);
        
    };
    
};
#endif
