#include <iostream>
#include <sodium.h>
#include <stdexcept>
#include "PasswordHasher.hpp"

using namespace std;

bool PasswordHasher::init(){
    if (sodium_init() < 0) {
        /* panic! the library couldn't be initialized; it is not safe to use */
    }
    return 0;
}

string PasswordHasher::hash(const string& password){
    char hash_out[crypto_pwhash_STRBYTES];
        if (crypto_pwhash_str(hash_out,
                    password.c_str(),
                    password.size(),
                    crypto_pwhash_OPSLIMIT_INTERACTIVE, 
                    crypto_pwhash_MEMLIMIT_INTERACTIVE) != 0){
                        throw runtime_error("erreur de mot de passe !");
                      }
                      return string(hash_out);
    }

bool PasswordHasher::verify(const string& hashed_password, const string& tested_password){
    return crypto_pwhash_str_verify(hashed_password.c_str(),
                             tested_password.c_str(),
                             tested_password.size()) ==0;
}

