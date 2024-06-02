class Solution {
public:
    
   
/*
Aakhir es que me jo bola hai, uska matlab huaa, * ke nearest ka minimum element jo bhi ho

Clear statement nhi lga(aao samjhata hu)

(......................)*
ye dot * ke aane ke pehle ka subarray hai thik,
to hme sabse minimum choose krna hai.

to tum bologe Abhishek bhai, to phir sidhe bolane ka n, ye complex karke kyu bola tumne
* ke nearest ka minimum element jo bhi ho

Gajab ho tum Abhishek bhai, aasan rakhne ka, complex kar rhe faltu ka

Arey bhai thamba thamba, dekho dekho aise bolna jaruri hai kyuki

aao dikhata hu

(aaba)*
to kaun sa a htavoge, es range me to minimum a hai, bolo bolo
arey bolte kyu nhi..\U0001f602\U0001f9d8

Samjhe to jo minimum elements hai, usme jo sabse pass hai * ke usko htana hai

to tum keh rhe abhishek bhai ye to complex lag rha,
arey tumhara bhai, rumhare sath hai chinta nhi karne ka, aasan karna mera kaam

(.....................) *

achcha to hme koi aisa jadu karna hai, jisse ki hme use dot dot ka minimum element mil jaye

Audience be like :- mai samjh gya, mai samjh gya \U0001f602
mai ya to (minPQ, multiset) use kr lunga

thik thik hai, ruk jao itna khush mat hovo

minPQ me vo element top me hoga jiski value minimum hogi.
Audience:- ekdam thik bola tumne
Abhishek:- achcha ek baat btavo minPQ kya karta hai jab same element hota hai.

Audience:- Aaye...e ka bol diye, dekh rha hai binod, tej ban rha hai

Abhishek:- guss na hoiye malik, achcha ek baat hai mai PQ me index ke sath elment ko rakhuga
Audience:- kyu, terese aasani se kaam nhi hota kaa..
Abhishek:- arey pop karte time kaise pta chalega ki kaun sa element huaa hai

Audience:- thik hai thik hai, ham samjh gye the, tumhara knowledge check kr rhe the, aati hi hai ya bas bolte ho

Abhishek:- thik to agree karte ho index ko sath rakhna hai character ke, thik. achcha ek baat btavo agar mai ind bhi rakha hai aur
            do character hai same hai to top pe kaun hoga 
            string => caa*
            Que time :- {a,1},{a,2};
            to top pe kaun hoga ? {a,1} ya {a,2}=> {a,1} n ye to fash gye
    
    Audience dar gyi Audience dar gyi \U0001f602\U0001f602\U0001f602\U0001f602\U0001f602
    
ab bolo binod.

Audience:- be like, ka bawasir que hai, ek chij socho ek chij pe fash jaoo

Abhishek:- dekho agr kaisa ho ki first value min ho and second value maximum agr vo top pe aa jaye to mza hi aa jaye

Audience:- e kaise hoga

Abhishek:- bole to comperator se bhaiya

        mazak se hat ke, agr comperator se familiar nhi ho to YT pe video dekh lena(comperator ki, kisi aur ki mat dekhna)
        
        
bas que khatam, * aaye PQ ke top ko pop karo and kaam khatam.
Lekin ek minute aakhir tum answer wala string kab banaoge

dekho jab jab jo pop hoga, uski index mark kar dunga, phir pura traverse krke, unmark ind ko add kr dunga simple hai simple hai

Audience:- Samjh aa gya, tere explanation me daam nhi th, hmare dimak me daam hai \U0001f60e\U0001f60e\U0001f60e\U0001f60e


Agr doubt hai to feel free to ask in comment section, baaki milte hai kabhi...dusari post me \U0001f602
*/
     
    
    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first)
                return a.second < b.second;  
            return a.first > b.first; 
        }
    };
    
    string clearStars(string s) {
        int n=s.size();
        string ans="";

        // ascii code to suna hi hoga tumne
       priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                // jo pop visit kar diya
                vis[pq.top().second]=1;
                pq.pop();
                
                // ye star ko visit kar rha, vo to answer ka hissa hoga hi nhi
                vis[i]=1;
            }else{
                // ascii ka kamal
                pq.push({s[i],i});
            }
        }
        
        for(int i=0;i<n;i++){
            // jo visit nhi vo answer me jayega
            if(vis[i]==0){
                ans.push_back(s[i]);
            }
        }
        
        return ans;
    }
};