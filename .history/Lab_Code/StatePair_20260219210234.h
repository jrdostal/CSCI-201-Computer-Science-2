#ifndef STATEPAIR
#define STATEPAIR

template<typename T1, typename T2>
class StatePair {

// TODO: Define constructors
   StatePair();
   StatePair(T1 userKey, T2 userValue);
   
// TODO: Define mutators, and accessors for StatePair
   void SetKey(T1 userKey);
   void SetValue(T2 userValue);
   T1 GetKey();
   T2 GetValue();
	
// TODO: Define PrintInfo() method
    void PrintInfo();
    
private:
   T1 key;
   T2 value;

};



StatePair::StatePair(userKey, userValue) {
   key = userKey;
   value = userValue;
}

void StatePair::SetKey(T1 userKey) {
   key = userKey;
}

void StatePair::SetValue(T2 userValue) {
   value = userValue;
}

T1 StatePair::GetKey() {
   return key;
}

T2 StatePair::GetValue() {
   return value;
}

void StatePair::PrintInfo() {
   cout << key << " " << value << endl;
}

#endif //STATEPAIR
