## INSERTING ELEMENTS OF ONE DATA STRUCT. TO VECTOR ARRAY ;-

  # ans.insert(position,first_iterator,last_iterator); #

     
 EX:- vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {4, 5, 6};

    v1.insert(v1.end(), v2.begin(), v2.end());

    for (auto x : v1)
        cout << x << " ";
}

Output:

1 2 3 4 5 6


EX:-
    set<int> st = {10, 20, 30, 40};
    vector<int> v = {1, 2};

    v.insert(v.end(), st.begin(), st.end());

    for (auto x : v)
        cout << x << " ";
}

Output:

1 2 10 20 30 40
