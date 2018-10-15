# include <bits/stdc++.h>
           
struct node {
  node *l, *r;
  int sum;
};  
node* update (node *v, int tl, int tr) {
  if (tl == tr)
    return new node();                 
  node *nt = new node();
      
  int tmid = (tl+tr) >> 1;
  if (tl <= tmid)
    nt->l = update (v->l
