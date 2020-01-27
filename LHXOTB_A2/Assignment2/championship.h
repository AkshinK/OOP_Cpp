#pragma once

#include <fstream>
#include <sstream>
#include <string>

struct Contest {
    std::string angler;
    std::string championship;
    bool exist;
};

class ChampEnor{
    public:
        ChampEnor(const std::string &str) { _f.open(str); };
        void first() {next();}
        void next();
        Contest current() const { return _cur;}
        bool end() const { return _end;}
    private:
        Contest _cur;
        std::ifstream _f;
        bool _end;
};

