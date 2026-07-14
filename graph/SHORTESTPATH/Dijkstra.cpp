LOGIC USED IN DIJKSTRA -->>
"https://www.geeksforgeeks.org/dsa/dijkstras-shortest-path-algorithm-greedy-algo-7/"

Dijkstra ka idea hai: hamesha source se sabse nearest unprocessed node ko pehle fix karo.
 Uske shortest distance ka use karke uske neighbours ke distances improve (relax) karo. 
 Is tarah shortest paths layer by layer bahar ki taraf expand hote jaate hain

** BAISC IDEA -> simply travers over the graph and if smaller path/distance is found for  a node update the dist vector and agin push the node to data structrue 
Now earlier hum queue use kr rhe the , but queue me smallest ditance valla node top/front pe nhi ata  tho longer ditance vala node bhi pahele compute ho skta h this will vaste  a lot of time complexity 
therefore we sue priority queue and sets 


"Queue use nahi karte " / queue answer tho dedegi but more time 
queue me  bada distance wala node bhi pehle process ho sakta hai. 
Baad me agar usi node ka chhota distance mil gaya, to us node aur uske descendants ko dobara process karna padta hai,
 jisse unnecessary computations badh jaati hain. 


"##### Dijkstra me Priority Queue kyu use karte hain?"
Agar kisi node ka aur bhi chhota distance mil jata hai, to sirf us node ka distance update karna kaafi nahi hota.
Uske baad us node ke saare children, unke children (grandchildren), ... sabka distance bhi dobara check karna padta hai, kyunki ab un tak pahunchne ka ek aur chhota path mil gaya hai.
isliye node ko dobara push krna padta hai isse bachne ke liye  Priority Queue (Min Heap) use karte hain.

Priority Queue ka rule:
Jis node ka source se sabse chhota distance hoga, wahi sabse pehle process hoga.
Isse fayda kya hota hai?

Maan lo do paths hain:
Ek parent tak distance = 20
Dusra parent tak distance = 8

Priority Queue pehle 8 wale parent ko process karegi.
Agar us path se children ka bhi distance kam ho gaya, to unke distances update ho jayenge aur wahi updated (smaller) distances aage propagate honge.

Ab jab baad me 20 distance wale parent ki baari aayegi, uske children ke paas already usse bhi chhote distances honge.

" un children ko dobara process/push karne ki zarurat nahi padegi."

Agar Priority Queue na hoti...
Maan lo pehle galti se 20 distance wale parent ko process kar diya.

Uske children ko bhi large distances mil gaye.
Fir unke grandchildren bhi usi bade distance ke basis par compute ho gaye.

Baad me jab 8 distance wala parent process hoga, to pata chalega ki:

Children ka distance aur chhota ho sakta hai.
Isliye children ko dobara update karna padega.
Phir grandchildren ko bhi dobara compute karna padega.
Agar unka distance bhi kam hua, to unke children ko bhi dobara...
Ye process baar-baar repeat hoga.

Yaani unnecessary recomputation bahut zyada ho jayegi.


"NOTE===>> DIJKSTRA DOESNT WORK WITH NEGATIVE WEIGHTSS !!!!!!"


SETS:::--->>>

Now if we use sets if at same time for a node mutliple ditsnacce are present it will keep the smallest distance vala becuae hum {dist,node} pass krenge 




very importsnt ::: APAN P
"IF YOU POP ANY {DIST,NODE} THEN THAT DIST IS FINAL DIST FOR THAT NODE " BECUASE 
if we are popping means its dist is smallest currently in set AUR TU SOCH RHA H AGR AAGE JAK SMALLER DITSNCE MIL JAYE BUT YE POSSIBLE NHI H 
ex:
 the priority queue contains something like:
(5, B)
(8, C)
(10, D)
...
Since its a min-heap, 5 is the smallest distance among all unprocessed nodes.Suppose B is popped with distance = 5
To reach B later, you must come through some other node X.

Source -----> X -----> B
But notice:
B was popped with distance 5.
Since B was the smallest in the PQ, every unprocessed node X has distance ≥ 5. AUR FIR B TAK KE LIYE TUZHE X ME KUCH ADD KRNA HOGA 

AUR SINCE B KA FINALHO GYA IT MEANS B KE 



   vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
    
    //form standard adj list
    vector<vector<pair<int,int>>> adj(V);
    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        int d = edge[2];
        adj[u].push_back({v,d});
        adj[v].push_back({u,d});
    }
    
    
    //form pq   //{distance,node}
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    
    //dist array
    vector<int> dist(V,INT_MAX);
    dist[src] = 0;
    
    pq.push({0,src});
    while(!pq.empty()){
        int distance = pq.top().first; // distance till node/parent from source 
        int node = pq.top().second;
        pq.pop();
        
        //agr node ke pass ane ka laready chota rasta ha tho leave this path 
        if(distance>dist[node]) continue ;
        
        for(auto neigh : adj[node]){
         int edgeWeigh = neigh.second;
         int vertex = neigh.first; //child node
         
         if(edgeWeigh + distance < dist[vertex]){
             dist[vertex] = edgeWeigh + distance ;
             pq.push( { dist[vertex] , vertex } );
         }
        }
    }
    //given connected 
    
    return dist;
    }


    USING SETS ===>
	
		st.insert({0, src});
		while (!st.empty()) {
			auto [distance, node] = *st.begin();
			st.erase(st.begin());
			
			// agr node ke pass ane ka laready chota rasta ha tho leave this path
			if (distance>dist[node])
				continue ;
			
			for (auto neigh : adj[node]) {
				int edgeWeigh = neigh.second;
				int vertex = neigh.first; // child node
				
				if (distance + edgeWeigh < dist[vertex]) {
					if (dist[vertex] != INT_MAX)        //LARGE DISTANCE VALE PATH KO HATTA DE YAHI FAYDA H SET KA 
						st.erase({dist[vertex], vertex});
					dist[vertex] = distance + edgeWeigh;
					st.insert({dist[vertex], vertex});
				}
			}
		}
		// given connected