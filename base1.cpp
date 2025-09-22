#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<float> choisir_note() {
    float a;

    vector<float> v;
    for (int i = 0; i<5; i++){
      cout << "Choisis la "<<i+1<<" ème note : " << endl;
      cin >> a;
      v.push_back(a);
    }

    for (float n: v){
      cout<<n<<" ";

    }
    return v;
}
void Stat(const vector<float> &v){
  vector<float>results;
  auto result = minmax_element(v.begin(), v.end());
  float min = *result.first;
  float max = *result.second;


  float mean = accumulate(v.begin(), v.end(), 0.0f);
  mean = mean/v.size();

  results.push_back(min);
  results.push_back(max);
  results.push_back(mean);

  cout<<"\n voici les stats\n ";
  for (float n : results){
    cout<<n<<" ";
    }



}





int main() {
    vector<float> notes = choisir_note();
    
    Stat(notes);
    return 0;
}
