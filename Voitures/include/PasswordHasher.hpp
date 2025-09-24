#ifndef PASSWORDHASHER_CPP
#define PASSWORDHASHER_CPP

class PasswordHasher {
    public : 

    static bool init();

    static std::string hash(const std::string& password);

    static bool verify(const std::string& hashed_password,const std::string& password_test );

};

#endif