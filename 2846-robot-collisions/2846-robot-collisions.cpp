/*
Achcha bhai umeed hai que samjh aa gya hoga ekdam achche se
To aaiye suru karate hai.

Bhairava (bounty hunter) , Bujji(AI)

Bhairava:- Bujji aaj ka leetcode ka POTD dekha samjh nhi aa rha.
Bujji:- Hn dekha bhairava bahot aasan to hai.
Bhairava:- Sabke liye nhi bujji, mere uper se gya, samjha do, plz.

Bujji:- Chalo rovo mat, samjha deti hu.
        Dekho Bhairava es que me bola hai ki bahot sare robots hai
        mai apni baat nhi kar rhi mere taraf mat dekho.
        To vo n ya to Right ya phir left move kar rhe hai.
        Same speed se, to obivious hai ki collision hoga unke beech.
        kyu bhairava hoga n ?

Bhairava:- Hn Hn bilkul hoga, jaise do gadi move karti hai to takara 
        jati hai vaise hi robot bhi taraka jayenge.
        lekin bujji sari gadi same speed se chal rhi hai to takkar
        hogi kaise, kyuki que me to bola hai ki sabki position alg
        hogi ?

Bujji:- Bhairava tum itne intelligent ho ? maine socha nhi tha.
    tumhara doubt bilkul shi hai lekin esme ek observation hai.
    Dhyan se sunna repeat nhi karungi.
    Uper ki image dekho jaldi, dekho agr vo same direction me move
    karenge to kabhi takkar nhi hogi, but jab vo different direction
    me jayenge tabhi takkar hogi.
    May be uper se gya hai, just close you eye (bhai tumhe nhi karna
    padho aur imagine kro, jo bolunga vo kuchch aur nhi).
    Yaad kro jab tum ek bus pichche khub masti me ja rhe the thik n
    tabhi bus wale me apni speed kam kar di, tum udati speed me jake
    bus ki pichche se thok diye aaram se, jinda ho tum chinta na kro.
    (coder be like DSA ne maar rakha hai, marne se dar nhi lagta \U0001f602.)

    Achcha collison esiliye huaa kyuki speed dono ki alag alg hai but
    jab bus slow hui but tum nhi tabhi collision huaa.
    Lekin esme n speed same hai, to n kabhi same direction me jane 
    pe collision nhi hoga kyuki sabki position diff hai, dekho que me
    mention hai, que bnane wale mje ke liye nhi likha \U0001f602.

    To suppose tum bus ke pichche aur same direction me move kar rhe
    ho but but tumhare aur bus me thoda sa gaph hai aur tum dono chal
    rhe same speed se, to t time me tum jitna distance cover kroge
    utna bus bhi karegi to kya kabhi takkar hogi nhi n?
    Ab samjh aaya, jab position sabhi alg hai, speed same hai to 
    same direction me collsion to nhi hogi but kya ho jab vo bus 
    tumhare aage se aa rhi hogi, tab to agye (swarg bahi sahab :- kya
    keh rhe itne achche karm bhi nhi hai).

    Basic mudda ye tha ki:- que me mention condition ke karan, takkar
                            hamesha diff direction me aane me hogi
                            but but .... abhi khel pura nhi huaa

    Suppose :- ek gadi left ja rhi ek gadi right me to jruri nhi ki,
            collision hoga hi, collision hone ke liye. Left jane wali
            gadi ko aage position pe khda hona hoga,
            tabhi collision hoga.

        Confuse huye n, img2 dekho samjh jaoge. Phir es line koi re-
        -read kro, samjh aa jayega, nhi to comment kar do.

Bhairava:- Samjh gya bujji, ye itna kathin kyu lag rha \U0001f611.
Bujji:- Bhairava dhyan do samjh jaoge.


Bhairava:- bujji collision to samjh aa gya ab solve kaise kare.
Bujji:- dekho bhairava ham n position ke according sort karenge
        aur dekhenge ki.

Bhairava:- kya bujji, kar di vhi farji baat, kyu sort kre,

Bujjji:- dekho bhairva, sort krke ham ek chij sure kar payenge ki 
        aane wala jo bhi robot hai vo uske aage hai, yani yaad kro
        collision wali line maine kya bola tha ki, pichche hoga right
        jaane wala tabhi collision hoga.
 
    Ya phir aise dekh lo suppose ki mai kisi ith robot pe hu aur
    mai dekhna chahta hu ki kisse collision hoga, to mujhe kuchch 
    baate dhyan deni padegi:-

    2 case banega :- 
    1) ith jab R side ja rha ho :-
        es case me tum ek aisa robot khojoge to, ith ke position se aage
        ho aur left side aa rha ho, tabhi takkar hogi.

    Es line ko read kro aur copy pe ek diagram banao thik
    samjh jaoge kya bol rha hu.

    2) jab ith L side ja rha ho :- 
        to tum ek aisa robot khojoge jo right side ja rha aur ith ke 
        position ke pichche ho.

    I hope ye dono line samjh aa gyi hogi.

To Bhairava dekh rhe ho eske liye tumhe pura array traverse karna 
padega kyuki tumhe pta nhi hoga ki minimum kis side maximum kis side
shi bola n maine, agr maine sort kar diya to agr mai ith pe khda hu to
ye to mujhe confirm hoga ki, mere pichche jitne hai vo mere se potion
wise bhi pichche jo mere baad hai, vo position me aage hai.

Doutb huaa, read again, if again issue -> leave a comment.

Bhairava:- ye hui n bujji wali baat, reason dena chaiye har chij ka.
    mza aa gya bujji.

Bujji:- Bhairava zyada khush nhi hona hai, abhi que pura nhi huaa.

Ab code me chalate hai vnha har line ko explain krungi, thik n
ynha feel nhi aayega.

*/

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {

// bujji and bhairava rest pe gye unhoone ab ynha se mujhe bhej diya
// mai abhirai1...thoda noob hu, kuchch galat bol du to, mafi \U0001f642

        // simple varable declare kiya
        int n=positions.size();
        vector<int> ans; 

        // aayen, stack par kyu bhai.
        stack<pair<int,int>> st; 
/*
Why stack ?

Ye thodi si practice wali baat hoti hai, jaise ki dependency jaisi thi, dependency (dekh abhirai1, ye faltu word use krke confuse nhi 
karna, aasani se samjha).
Gussa nhi malika, que ka ek line yaad kriye.
Que me do situation given hai, jab collison hoga

1) health same -> dono bahar
2) diff -> maximum one win (but health--)
    aise samjho truck aur cycle ki takkar, achchi heath wala jitega
    bas thoda bahtu minor sa damage hoga truck ho jo ki huaa (-1), 
    lekin cycle wala to puri tarah gya n.

Suppose:- 

    (---ye sab robot right ja rhe)   X(ye x robot left ja rha)

    ab maan lo eski heath infinite, JCB man lo \U0001f602, pichche wali sab 
    cycle, to ye jab tak udata jayega jab tak eski health,aane 
    wale se zyada hogi (arey bhai maximum wins wala case).
    aur ek baar udane pe -1 to hoga hi heath.

    to dekho mai kisi i pe khda hoke apne pichche ke elements ko dekh
    rha, to aisi dependency me maximum time stack lagta hai.

Malik ab samjh aaya malik \U0001f602\U0001f602\U0001f602\U0001f602.
        
*/      
        // simple store and sort
        // ind es liye taki, jiski bhi
        // health ya dir chaiye ind se mil jayegi, baki position to 
        // hogi hi
        vector<pair<int,int>> ip; 
        for(int i=0;i<n;i++) ip.push_back({positions[i],i});
        sort(ip.begin(),ip.end()); 

/*
Audience:- achcha hamesha collision ke liye tum pichche kyu dekh rhe ?
Abhirai1:- Good question,
        dekho position sorted hai, mai pichche tabhi dekhunga, jab
        koi left side move krne wala aayega, tabhi collision hoga n.
        Lekin collision tabhi hoga jab us left jaane wale se pehle
        koi uske pichche ka right me move kar rha ho.
Prefer img2.
*/

        for(auto it:ip){
            int pos=it.first; 
            int ind=it.second; 
            char dir=directions[ind]; 
            
            // agr koi pichche nhi to collision kisse
            // ya phir koi right me move kar rha hai to collison hoga
            // ho nhi
            // Audience :- ye kaise keh skte ho
            // abhirai1:- kyu suppose, jo R dir me move kar rha
            // hai uske pichche 2 prakar ke robot ho skte hai
            // ek jo right me jaye
            // ek left me jaye
            // R-R no collision
            // L-R no collison kyuki 
            // R ki position zyada hogi left wale se esiliye.
            // refer img2 and read again.

            // if any doubut, feel free to ask.
            if(st.size()==0 || dir=='R'){
                st.push({pos,ind});
            }
            else{

                // dekho collison hona hai to pichche wale ko right 
                // aur aage wale ko left move karna hoga
                // img2 refer kro
                
                // pichche wale sare stack me hai
                // bas vhi likha hai
                // agr ye hold kar rha to collision hoga
                while(st.size()>0 && directions[st.top().second]=='R' && dir!=directions[st.top().second] && healths[ind]>healths[st.top().second]){       
                    // stack wale hi heath kam to out yani zero
                    healths[st.top().second]=0;
                    // ith powerful to -1
                    healths[ind]--;
                    st.pop();
                }

                if(st.size()>0 && directions[st.top().second]=='R' && dir!=directions[st.top().second] && healths[ind]==healths[st.top().second]){          // man lo agr dono ki health same to dono khatam
                    //  to dono ki health zero
                    healths[st.top().second]=0;
                    healths[ind]=0;
                    st.pop();

                    // ye tum socho kyu continue
                    //test case

                /*  
                    positions = [3,5,2,6]
                    healths = [10,10,15,12]
                    directions = "RLRL"
                */

                // mujhe kafi achcha lagega, agr kyu proper solid 
                // reason comment kar dega, ki break kyu lagana hai
                // esse pta chalega ki kitne deep, me samjhe ho.
                // All the best
                    continue;
                }

                if(st.size()>0 && directions[st.top().second]=='R' && dir!=directions[st.top().second] && healths[ind]<healths[st.top().second]){           // agr stack jita jo sirf uski health kam hogi
                    healths[st.top().second]--;
                    healths[ind]=0;
                }

                // baki agr suppose karo
                // jitne stack me the robot un sab ko
                // takkar mar ke agr jo bahar ith robot hai uski
                // kuchch bhi health bachi to usko stack me push to
                // kroge he.
                // to ye check karna, ki bahar wala winner hai
                // to uski ye condition hogi

                // agr dir same hogi to collision to hoga hi nhi
                // to simple push kar denge
                // ek baar batau ek dir same wala case tum if me 
                // include kar skte ko, jo start wala tha
                // to ynha pe check nhi karna padega.
                if((st.size()==0 && healths[ind]>0) || (st.size()>0 && dir==directions[st.top().second]))  st.push({pos,ind});

            }
        }

        // traverse aur usi order me answer
        for(auto it:healths) if(it!=0) ans.push_back(it);

/*
umeed karta hu samjh aa gya hoga,
ratti bhar bhi logic, intution me dikkat hai, 
ping me, i will definetly try to help you, if i can.

Que karne ka matlab uska chit pat sab pta hona chaiye

*/
        // happy coding \U0001f496
        // Bye Bye...
        return ans;
    }   
};