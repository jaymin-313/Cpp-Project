#include<iostream>
#include<cstring>
#include"..\include\exception.h"
#include"..\include\string.h"

namespace utility {

    char String::operator[](int index) {
        try {
            if (index > m_Size || index < 0) {
                throw utility::myException("Index out of bound");
            }
        }
        catch (const myException& e) {
            std::cout << "Caught Exception : " << e.what() << std::endl;
            return 0;
        }

        return m_Buffer[index];
    }

    void String::getlength() const {
        std::cout << m_Size << std::endl;
    }
    void String::flush() {
        m_Buffer.reset();
        m_Size = 0;
    }
    void String::tolowercase() {
        for (int i = 0; i < m_Size; i++) {
            m_Buffer[i] = tolower(m_Buffer[i]);
        }
    }

    void String::touppercase() {
        for (int i = 0; i < m_Size; i++) {
            m_Buffer[i] = toupper(m_Buffer[i]);
        }
    }
    void String::print() const {
        std::cout << m_Buffer << std::endl;
    }
    void String::concatenate(const String& other) {
        if (other.m_Size != 0) {
            size_t newSize = m_Size + other.m_Size;
            std::unique_ptr<char[]> result = std::make_unique<char[]>(newSize + 1);
            memcpy(result.get(), m_Buffer.get(), m_Size);
            memcpy(result.get() + m_Size, other.m_Buffer.get(), other.m_Size + 1);

            m_Size = newSize;
            m_Buffer = std::move(result);
           
        }
    }
    String String::intToString(int num) {

        auto temp{ num };
        auto count{ 0 };
        if (temp < 0) {
            ++count;
            temp = -temp;
        }
        while (temp > 0) {
            temp = temp / 10;
            count++;
        }

        auto* newBuffer = new char[count + 1];

        if (num < 0) {
            newBuffer[0] = '-';
            num = -num;
        }

        auto i{ count - 1 };
        while (num > 0) {
            newBuffer[i] = num % 10 + '0';
            num = num / 10;
            --i;
        }
        newBuffer[count] = '\0';


        String result{ newBuffer };

        delete[] newBuffer;

        return result;
    }
}
std::ostream& utility::operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_Buffer;
    return stream;
}
