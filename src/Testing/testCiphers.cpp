#include "Cipher.hpp"
#include "CipherMode.hpp"
#include "gtest/gtest.h"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"
#include "CipherMode.hpp"

#include <string>

bool testCipher( const Cipher& cipher, const CipherMode mode, const std::string& inputText, const std::string& outputText){
    return cipher.applyCipher(inputText, mode) == outputText;
}

TEST(Cipher, Encrypt){
    CaesarCipher cc{5};
    EXPECT_TRUE(testCipher(cc, CipherMode::Encrypt, "HELLOWORLD", "MJQQTBTWQI"));
    PlayfairCipher pc{"playfairexample"};
    EXPECT_TRUE(testCipher(pc, CipherMode::Encrypt, "HELLOWORLD", "DMYRANVQCRHV"));
    VigenereCipher vc{"KEY"};
    EXPECT_TRUE(testCipher(vc, CipherMode::Encrypt, "HELLOWORLD", "RIJVSUYVJN"));

}