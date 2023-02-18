template<typename T>
class ArrayList {
 private:
 	std::vector<T> list;

  public:
  	ArrayList() {}

  void add(T item) {
    list.push_back(item);
  }

  void remove(int index) {
    list.erase(list.begin() + index);
  }

  T get(int index) {
    return list[index];
  }

  int size() {
    return list.size();
  }
  
  bool contains(T item) {
    for(int i = 0; i < list.size(); i++) {
      if(list[i] == item) {
        return true;
      }
    }
    return false;
  }
  
  bool equals(char *str1, char *str2){
		
		for(int i = 0; str1[i] != 0 || str2[i] != 0; i++){
			
			if(str1[i] != str2[i]){
				return false;
			}
		}
		
		return true;
	}
  
  int getIndexOf(T item){
  	
    for(int i = 0; i < list.size(); i++) {
      if(list[i] == item){
        return i;
      }
    }
    
    return -1;
  }
  
  void set(int index, T item) {
    list[index] = item;
  }
  
  void removeDuplicates() {
    for (int i = 0; i < list.size(); i++) {
      T item = list[i];
      for (int j = i + 1; j < list.size(); j++) {
        if (item == list[j]) {
          remove(j);
          j--;
        }
      }
    }
  }
  
  
  int count(T item) {
    int count = 0;
    for (int i = 0; i < list.size(); i++) {
      if(list[i] == item) {
        count++;
      }
    }
    return count;
  }
  
	//Alfabeticamente abaixo
	bool afb_low(char *a, char *b){
		
		if(strcmp(a, b) > 0){
			return true;
		}
		else{
			return false;
		}
	  	
	}
  
  void sort() {
    for (int i = 0; i < list.size() - 1; i++) {
      for (int j = 0; j < list.size() - i - 1; j++) {
      	
        if(afb_low(list[j], list[j + 1])) {
          T temp = list[j];
          list[j] = list[j + 1];
          list[j + 1] = temp;
        }
      }
    }
  }
  
};
