#include "HashTableTests.h"

using namespace vikas;

void run_all_tests() {
	test_add_exists();
	test_probing();
	test_get();
	test_remove();
}

void test_add_exists(){
	HashTable states(100);

	HashObject tx;

	tx.SetKey("India");
	tx.SetValue("Delhi");
	states.Add(&tx);

	assert(states.Exists("India"));
}

void test_probing() {
  // setting high load to force collisions
  HashTable states(8);
  HashObject tx;
  tx.SetKey("Texas");
  tx.SetValue("Austin");

  HashObject ca;
  ca.SetKey("California");
  ca.SetValue("Sacramento");

  HashObject nm;
  nm.SetKey("New Mexico");
  nm.SetValue("Santa Fe");

  HashObject fl;
  fl.SetKey("Florida");
  fl.SetValue("Tallahassee");

  HashObject oregon;
  oregon.SetKey("Oregon");
  oregon.SetValue("Salem");

  HashObject wa;
  wa.SetKey("Washington");
  wa.SetValue("Olympia");

  HashObject ut;
  ut.SetKey("Utah");
  ut.SetValue("Salt Lake City");

  HashObject ny;
  ny.SetKey("New York");
  ny.SetValue("Albany");

  HashObject mn;
  mn.SetKey("Minnesota");
  mn.SetValue("St. Paul");

  states.Add(&tx);  // 1
  states.Add(&ca);  // 0
  states.Add(&nm);  //
  states.Add(&fl);
  states.Add(&oregon);
  states.Add(&wa);
  states.Add(&ut);
  states.Add(&ny);
  states.Add(&mn);

  //  Texas:1
  //  California:0
  //  New Mexico:5
  //  Florida:5
  //  Oregon:4
  //  Washington:0
  //  Utah:6
  //  New York:7
  //  Minnesota:6

  //  0: California:Sacramento
  //  1: Texas:Austin
  //  2: Washington:Olympia
  //  3: New York:Albany
  //  4: Oregon:Salem
  //  5: New Mexico:Santa Fe
  //  6: Florida:Tallahassee
  //  7: Utah:Salt Lake City

  assert(states.Exists("California"));
  assert(states.Exists("New Mexico"));
  assert(states.Exists("Florida"));
  assert(!states.Exists("Minnesota")); // no room
}

void test_get() {
  HashTable states(100);

  HashObject tx;
  tx.SetKey("India");
  tx.SetValue("Delhi");
  states.Add(&tx);

  assert(states.Get("India") == "Delhi");
}

void test_remove() {
  HashTable states(100);

  HashObject tx;
  tx.SetKey("India");
  tx.SetValue("Delhi");
  states.Add(&tx);

  assert(states.Exists("India"));

  states.Remove("India");

  assert(!states.Exists("India"));
}