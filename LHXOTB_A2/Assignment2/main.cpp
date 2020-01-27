#include <iostream>
#include "angler.h"

using namespace std;

bool opt_search(const string &fileName)
{
    AnglerEnor t(fileName);
    bool l = true;
    for(t.first(); l && !t.end(); t.next()){
      //cout<<t.current().name<<" "<<t.current().contest_cnt<<endl;
      l = (t.current().contest_cnt >= 2);
    }
    return l;
}




#define NORMAL_MODE1
#ifdef NORMAL_MODE1

int main()
{
    if (opt_search("input.txt")) cout<<"True. All the anglers caught tuna at at least 2 championship"<<endl;
    else cout<<"False. Not all the anglers caught tuna at at least 2 championship"<<endl;

  return 0;
}



#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// opimistic_Search

TEST_CASE("empty file", "t0.txt") {
    CHECK_FALSE(opt_search("t0.txt"));
}

TEST_CASE("1 skillful angler, 2 contest", "t1.txt") {
    CHECK_FALSE(opt_search("t1.txt"));
}

TEST_CASE("1 unskillful angler, 2 contest", "t2.txt") {
    CHECK(opt_search("t2.txt"));
}

TEST_CASE("more anglers, more contests", "t4.txt") {
    CHECK(opt_search("t4.txt"));
}

TEST_CASE("only first one angler is skillful", "t6.txt") {
    CHECK_FALSE(opt_search("t6.txt"));
}

TEST_CASE("only last one angler is skillful", "t5.txt") {
    CHECK_FALSE(opt_search("t5.txt"));
}

TEST_CASE("all anglers succesful, but only last", "t7.txt") {
    CHECK_FALSE(opt_search("t7.txt"));
}
TEST_CASE("all anglers succesful, but only first", "t11.txt") {
    CHECK_FALSE(opt_search("t11.txt"));
}
TEST_CASE("one skillful angler among more anglers", "t5.txt"){
    CHECK_FALSE(opt_search("t5.txt"));
}
/////////////
//counting
TEST_CASE("No successful contest", "t8.txt") {
    AnglerEnor t("t8.txt");
    t.first();
    CHECK(t.current().contest_cnt == 0);
}

TEST_CASE("Multiple successful contests", "t9.txt") {
    AnglerEnor t("t9.txt");
    t.first();
    CHECK(t.current().contest_cnt == 4);
}

TEST_CASE("first angler is successful", "t2.txt") {
    AnglerEnor t("t2.txt");
    t.first();
    CHECK(t.current().contest_cnt == 2);
}

TEST_CASE("first angler no tuna", "t10.txt") {
    AnglerEnor t("t10.txt");
    t.first();
    CHECK(t.current().contest_cnt == 0);
}


// linear search

TEST_CASE("not any catch", "t8.txt") {
    ChampEnor tt("t8.txt");
    tt.first();
    CHECK(tt.current().exist == false);
}

TEST_CASE("1 catch", "t3.txt") {
    ChampEnor tt("t3.txt");
    tt.first();
    CHECK(tt.current().exist == true);
}

TEST_CASE("more fishes , no tuna", "t6.txt") {
    ChampEnor tt("t6.txt");
    tt.first();
    CHECK(tt.current().exist == false);
}

#endif
