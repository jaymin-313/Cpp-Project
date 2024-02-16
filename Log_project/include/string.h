
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

            memcpy(m_Buffer.get(), &string, m_Size);
            m_Buffer[m_Size] = 0;
           // return m_Buffer;
        }
        String& operator=(const String& string) {
           // std::cout << "Copy Assignment called" << std::endl;
            if (this != &string) {
                //delete[]m_Buffer;
                m_Size = string.m_Size;
               m_Buffer = std::make_unique<char[]>(m_Size + 1);
                memcpy(m_Buffer.get(), &string , m_Size);
                m_Buffer[m_Size] = 0;
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
        
        //String& operator+(String& other) {
        //   
        //        size_t new_size = m_Size + other.m_Size;

        //        char* new_data = new char[new_size + 1];
        //        memcpy(new_data, m_Buffer, m_Size);
        //        memcpy(new_data + m_Size, other.m_Buffer, other.m_Size);
        //        //strcat(new_data, other.m_Buffer);
        //        m_Size = new_size;

        //        delete[] m_Buffer;
        //        m_Buffer = new_data;
        //        m_Buffer[m_Size] = '\0';
        //        print();
        //        delete[] new_data;
        //        return *this;
        //}
        //
        char operator[](int) ;
        void getlength() const ;
        void tolowercase();
        void touppercase();
        void print() const;
        void concatenate(const String&);
        static String intToString(int);
        ~String() {
            //delete[] m_Buffer;
        }
        friend std::ostream& operator<<(std::ostream& stream, const String&
            string);
        
    };
    
};
#endif
