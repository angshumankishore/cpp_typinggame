#include <vector>
#include <string>
#include <cstdlib>  // for rand
#include <ctime>
#include <iostream> 

using namespace std; 

class WordBank{

		private:
				vector<string>wordbank; 
		public: 

				WordBank(){
						wordbank= {"apple","banana","mango","guava","pineapple"}; 
						srand(time(0)); 
				}


				string getrandomword(){
						int index = rand() % wordbank.size(); 
						return wordbank[index]; 
				}
				void pushword(string word){
						wordbank.push_back(word); 
				}
}; 

class Typinggame:public WordBank{
	private: 
			int score; 
			int rounds; 
			WordBank wordbank; 
	public: 

			Typinggame(int r): score(0),rounds(r){}

			void start(){


					for(int i = 0; i < rounds; i++){
							string input; 	
							string word = wordbank.getrandomword(); 
							cout << "Type this word " << word << endl; 
							cout << "Your input is " << endl; 
							cin >> input; 
							if(input == word){
									cout << "Correct " << endl; 
									score++; 
							}

							else{
									cout << "The correct word was " << word << endl; 
							}
							
					}

					cout << "Your score is " << score  << endl; 
			}
					
			

		
}; 
int main(){
		Typinggame game(2);
		game.pushword("orrange"); 
		game.start(); 
		return 0; 
}
