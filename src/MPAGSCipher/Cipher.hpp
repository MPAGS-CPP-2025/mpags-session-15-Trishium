#ifndef CIPHER_HPP
#define CIPHER_HPP

#include <string>
#include "CipherMode.hpp"

/**
 * \file Cipher.hpp
 * \brief Generic cipher class
 * 
 */

/**
 * \class Cipher
 * \brief Template class for a cipher with an applyCipher method
 */
class Cipher {
    public:
        /// @brief Constructors and destructors
        Cipher() = default;
        Cipher(const Cipher& c) = default;
        Cipher(Cipher&& c) = default;
        Cipher& operator=(const Cipher& c) = default;
        Cipher& operator=(Cipher&& c) = default;
        virtual ~Cipher() = default;

        /**
         * \brief Apply the cipher to the provided text
         * \param input the text to encrypt or decrypt
         * \param mode whether to encrypt or decrypt the input text
         */
        virtual std::string applyCipher( const std::string& input, const CipherMode mode) const = 0;

};

#endif