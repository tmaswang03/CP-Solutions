#include <bits/stdc++.h>
using namespace std;

class pieceTree;

class piece {
public:
    int c, r, i;
    bool ash;
    piece *below, *lowerLeft, *lowerRight, *left;
    bool iteratedBelow = false;
    bool iteratedLowerLeft = false;
    bool iteratedLowerRight = false;
    bool iteratedLeft = false;
    piece(int r, int c);
    piece(int r, int c, int i, bool ash);
    bool same(piece o);
    piece goLowerLeft(int k);
    piece goLowerRight(int k);
    piece goBelow(int k);
    piece goLeft(int k);
    string toString() {
        return "[("+to_string(r)+","+to_string(c)+")<=("+to_string(i)+","+(ash? "True":"False")+")]";
    }
    void link(set<piece> exists);
    bool operator <(piece o) const {
        if(r == o.r) return c < o.c;
        return r < o.r;
    }
    piece();
};
piece maxPlaceHolder = piece(0, 0, 0x3f3f3f3f, false);

class pieceTree {
public:
    pieceTree *left, *right;
    int l, r;
    piece maxV;
    pieceTree(vector<piece> pieces, int l, int r);
    piece minK(int k);
    piece query(int l, int r);
};

piece get_max(piece a, piece b) {
    if(a.i > b.i) return a;
    return b;
}
piece get_min(piece a, piece b) {
    if(a.i < b.i) return a;
    return b;
}

piece::piece(int r, int c) {
    this->r = r;
    this->c = c;
}
piece::piece(int r, int c, int i, bool ash) {
    this->r = r;
    this->c = c;
    this->i = i;
    this->ash = ash;
}
piece::piece() {}
bool piece:: same(piece o) {
    return r == o.r && c == o.c;
}
piece piece:: goLowerLeft(int k) {
    if(iteratedLowerLeft) return maxPlaceHolder; // basically maxPlaceHolder but c++ baf
    else {
        vector<piece> pieces;
        piece *next = this;
        while(next != nullptr) {
            cout << "LowerLeft: " << next->toString() << endl;
            pieces.push_back(*next);
            next->iteratedLowerLeft = true;
            next = next->lowerLeft;
        }
        return pieceTree(pieces, 0, pieces.size()-1).minK(k);
    }
}
piece piece:: goLowerRight(int k) {
    if(iteratedLowerRight) return maxPlaceHolder;
    else {
        vector<piece> pieces;
        piece *next = this;
        while(next != nullptr) {
            cout << "LowerRight: " << next->toString() << endl;
            pieces.push_back(*next);
            next->iteratedLowerRight = true;
            next = next->lowerRight;
        }
        return pieceTree(pieces, 0, pieces.size()-1).minK(k);
    }
}
piece piece::goBelow(int k) {
    if(iteratedBelow) return maxPlaceHolder;
    else {
        vector<piece> pieces;
        piece *next = this;
        while(next != nullptr) {
            cout << "Below: " << next->toString() << endl;
            pieces.push_back(*next);
            next->iteratedBelow = true;
            next = next->below;
        }
        return pieceTree(pieces, 0, pieces.size()-1).minK(k);
    }
}
piece piece::goLeft(int k) {
    if(iteratedLeft) return maxPlaceHolder;
    else {
        vector<piece> pieces;
        piece *next = this;
        while(next != nullptr) {
            cout << "Left: " << next->toString() << endl;
            pieces.push_back(*next);
            next->iteratedLeft = true;
            next = next->left;
        }
        return pieceTree(pieces, 0, pieces.size()-1).minK(k);
    }
}
void piece::link(set<piece> exists) {
    piece idealLeft = piece(r, c-1);
    piece val = *exists.upper_bound(idealLeft);
    left = val;
    if(left != exists.end()) if(!left->same(idealLeft)) left = exists.end();

    piece idealRight = piece(r, c+1);
    val = *exists.upper_bound(idealRight);
    piece *rht = val;
    if(rht != exists.end()) if(rht->same(idealRight)) rht->left = this;
    if(rht != exists.end() && rht->ash != ash) rht->left = exists.end();

    piece idealLowerLeft =  piece(r-1, c-1);
    val = *exists.upper_bound(idealLowerLeft);
    lowerLeft = val;
    if(lowerLeft != exists.end()) if(!lowerLeft->same(idealLowerLeft)) lowerLeft = exists.end();

    piece idealUpperRight = piece(r+1,c+1);
    val = *exists.upper_bound(idealUpperRight);
    piece *upperRight = val;
    if(upperRight != exists.end()) if(upperRight->same(idealUpperRight)) upperRight->lowerLeft = this;
    if(upperRight != exists.end() && upperRight->ash != ash) upperRight->lowerLeft = exists.end();

    piece idealLowerRight =  piece(r-1, c+1);
    val = *exists.upper_bound(idealLowerRight);
    lowerRight = val;
    if(lowerRight != exists.end()) if(!lowerRight->same(idealLowerRight)) lowerRight = exists.end();

    piece idealUpperLeft = piece(r+1,c-1);
    val = *exists.upper_bound(idealUpperLeft);
    piece *upperLeft = val;
    if(upperLeft != exists.end()) if(upperLeft->same(idealUpperLeft)) upperLeft->lowerRight = this;
    if(upperLeft != exists.end() && upperLeft->ash != ash) upperLeft->lowerRight = exists.end();

    piece idealBelow = piece(r-1, c);
    val = *exists.upper_bound(idealBelow);
    below = val;
    if(below != exists.end()) if(!below->same(idealBelow)) below = exists.end();

    piece idealAbove = piece(r+1,c);
    val = *exists.upper_bound(idealAbove);
    piece *above = val;
    if(above != exists.end()) if(!above->same(idealAbove)) above->below = this;
    if(above != exists.end() && above->ash != ash) above->below = exists.end();

    if(left != exists.end() && left->ash != ash) left = exists.end();
    if(below != exists.end() && below->ash != ash) below = exists.end();
    if(lowerLeft != exists.end() && lowerLeft->ash != ash) lowerLeft = exists.end();
    if(lowerRight != exists.end() && lowerRight->ash != ash) lowerRight = exists.end();
}

pieceTree::pieceTree(vector<piece> pieces, int l, int r) {
    this->l = l;
    this->r = r;
    if(l == r) {
        maxV = pieces[l];
    } else {
        int mid = (l + r)/2;
        left = new pieceTree(pieces, l, mid);
        right = new pieceTree(pieces, mid + 1, r);
        maxV = max(left->maxV, right->maxV);
    }
}
piece pieceTree::minK(int k) {
    piece ans = maxPlaceHolder;
    int l0 = this->l;
    int r0 = l0+k-1;
    for(; r0<=this->r; l0++, r0++) {
        ans = get_min(ans, query(l0, r0));
    }
    return ans;
}
piece pieceTree::query(int l, int r) {
    if(this->l == l && this->r == r) return maxV;
    else {
        if(r <= left->r) return left->query(l, r);
        else if(l >= right->l) return right->query(l, r);
        return get_max(left->query(l, left->r), right->query(right->l, r));
    }
}
int n, k, col[1000005];
int main() {
    cin >> n >> k;
    bool ash = true;
    set<piece> exists;
    for(int i=1; i<=n; i++, ash=!ash) {
        int c; cin >> c; col[c]++;
        piece cur = piece(col[c], c, i, ash);
        cur.link(exists);
        exists.insert(cur);
    }
    vector<piece> ascending;
    for(piece p : exists) {
        ascending.push_back(p);
        cout << p.toString() << endl;
    }

    piece ans = maxPlaceHolder;
    for(int i=ascending.size()-1; i>=0; i--) {
        piece cur = ascending[i];
        ans = get_min(ans, cur.goBelow(k));
        ans = get_min(ans, cur.goLowerLeft(k));
        ans = get_min(ans, cur.goLowerRight(k));
        ans = get_min(ans, cur.goLeft(k));
    }
    string winner = ans.ash? "Ashley" : "Oleg";
    cout << winner << " " << ans.i << endl;
    return 0;
}
