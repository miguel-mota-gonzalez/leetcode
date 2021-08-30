#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

/*
	For this problem we have group all related items in separated arrays

	map <char , vector<char>> input = { {'A', {'B','C','D'}}, 
										{'B',{'E','F'}}, 
										{'C',{}}, 
										{'D', {}}, 
										{'E', {'C','D'}}, 
										{'F',{}},
										{'G',{'E'}},
									    {'H',{'J'}},
									 	{'I',{'J'}},
										{'J',{}},
										{'K',{}},
										{'L',{}},
										{'M',{'K'}}
									  };
									  

Like this:
{A,B,C,D,E,F,G} 
{H J I}
{K M}
{L}								  

This is first brute force solution against the clock... it surely can and MUST be improved

*/

vector<vector<char>> getClusters(map<char, vector<char>> &input){
	vector<vector<char>> retVal;
	map<char , char> relations;
	map<char , vector<char>> rebuildArray;
	
	for(auto &item : input){
		char relatedTo='\0';

		// Do we have that key in relations?
		auto it = relations.find(item.first);
		if(it!=relations.end()){
			relatedTo=it->second;
		}

		// is any of my items in relations?
		for(char &c : item.second){
			auto it2 = relations.find(c);
			if(it2!=relations.end()){
				relatedTo=it2->second;
			}
		}

		// Is the current item in a relation?
		if(relatedTo!='\0'){
			// We have a relation
			vector<char> &relatedArray = rebuildArray[relatedTo];

            if(find(relatedArray.begin(), relatedArray.end(), item.first)==relatedArray.end()){
				relatedArray.push_back(item.first);
			}

			for (char &c : item.second){
				//Add to relations
				relations.insert(pair<char, char>(c, relatedTo));

				// Add to grouped array
				if(find(relatedArray.begin(), relatedArray.end(), c)==relatedArray.end()){
					relatedArray.push_back(c);
				}
			}
		}
		else{
			// Add the items to the relations map	
			relations.insert(pair<char, char>(item.first, item.first));
			for(char &c : item.second){
				relations.insert(pair<char, char>(c , item.first));
			}

			// Create a new grouped array
			vector<char> tmpArray;

			tmpArray.push_back(item.first);
			for(char &c : item.second){
				tmpArray.push_back(c);
			}

			rebuildArray.insert(pair<char , vector<char>>(item.first, tmpArray));
		}

	}

	for(auto finalItem : rebuildArray){
		retVal.push_back(finalItem.second);
	}

	return retVal;
}

int main(){

	map <char , vector<char>> input = { {'A', {'B','C','D'}}, 
										{'B',{'E','F'}}, 
										{'C',{}}, 
										{'D', {}}, 
										{'E', {'C','D'}}, 
										{'F',{}},
										{'G',{'E'}},
									    {'H',{'J'}},
									 	{'I',{'J'}},
										{'J',{}},
										{'K',{}},
										{'L',{}},
										{'M',{'K'}}
									  };



	vector<vector<char>> result = getClusters(input);

	for(auto &array : result){
		for(char &c : array){
			cout << c << ' ';
		}
		cout << std::endl;
	}

	return 0;
}
