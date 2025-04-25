#include <vector>
#include <string>
#include <cstdlib>  // for rand
#include <ctime>
#include <iostream> 
#include <chrono> 
//trying out a demo comment 
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
			int wordcount = 0; 
			int rounds; 
			WordBank wordbank; 
	public: 

			Typinggame(int r): score(0),rounds(r){}

			void start(){
					
					auto start = chrono::high_resolution_clock::now(); 

					for(int i = 0; i < rounds; i++){
							string input; 	
							string word = wordbank.getrandomword(); 
							cout << "Type this word " << word << endl; 
							cout << "Your input is " << endl; 
							cin >> input; 
							wordcount += input.length(); 
							if(input == word){
									cout << "Correct " << endl; 
									score++; 
							}

							else{
									cout << "The correct word was " << word << endl; 
							}
							
					}

					auto end = chrono::high_resolution_clock::now(); 
					chrono::duration<double>elapsed = end - start; 
					double seconds = elapsed.count(); 	
					double wpm = (wordcount/5.0)/(seconds /60.0); 


					cout << "Your score is " << score << " and wpm is " << wpm << endl; 
			}
					
			

		
}; 
int main(){
		Typinggame game(3);
		game.pushword("orrange"); 
		game.start(); 
		return 0; 
}
