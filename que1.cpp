#include<iostream>
using namespace std;

struct Point {
	float x, y;
};

struct line {
   Point p1, p2;
};

bool onLine(line l1, Point p) {        
   if(p.x <= max(l1.p1.x, l1.p2.x) && p.x <= min(l1.p1.x, l1.p2.x) &&
      (p.y <= max(l1.p1.y, l1.p2.y) && p.y <= min(l1.p1.y, l1.p2.y)))
         return true;

   return false;
}

int direction(Point a, Point b, Point c) {
   int val = (b.y-a.y)*(c.x-b.x)-(b.x-a.x)*(c.y-b.y);
   if (val == 0)
      return 0;           
   else if(val < 0)
      return 2;          
      return 1;          
}

bool isIntersect(line l1, line l2) {
   
   int dir1 = direction(l1.p1, l1.p2, l2.p1);
   int dir2 = direction(l1.p1, l1.p2, l2.p2);
   int dir3 = direction(l2.p1, l2.p2, l1.p1);
   int dir4 = direction(l2.p1, l2.p2, l1.p2);

   if(dir1 != dir2 && dir3 != dir4)
      return true;           
   if(dir1==0 && onLine(l1, l2.p1))
      return true;
   if(dir2==0 && onLine(l1, l2.p2))
      return true;
   if(dir3==0 && onLine(l2, l1.p1))
      return true;
   if(dir4==0 && onLine(l2, l1.p2))
      return true;
   return false;
}

bool checkInside(Point poly[], int n, Point p) {
   if(n < 3)
      return false;                  
   line exline = {p, {9999, p.y}};   
   int count = 0;
   int i = 0;
   do {
      line side = {poly[i], poly[(i+1)%n]};
      if(isIntersect(side, exline)) {          
         if(direction(side.p1, p, side.p2) == 0)
            return onLine(side, p);
         count++;
      }
      i = (i+1)%n;
   } while(i != 0);
      return count&1;             
}

int main() {
   
   int n;
   bool res = true;
   cout<<"Enter number of point of polygon";
   cin>>n;
   struct Point polygon[n];
   struct Point p;
   for(int i=0;i<n;i++){
   	cout<<"Enter "<<i+1<<"th x cordinate"<<endl;
	cin>>polygon[i].x;
   	cout<<"Enter "<<i+1<<"th y cordinate"<<endl;
	cin>>polygon[i].y;
   }
   cout<<"\n\nEnter point p"<<endl;
   cout<<"\nEnter x coordinate of  point p"<<endl<<endl;
   cin>>p.x;
   cout<<"\nEnter y coordinate of  point p"<<endl<<endl;
   cin>>p.y;
  

   if(checkInside(polygon, n, p))
	   cout<<boolalpha<<res<<endl;
   
   else{
	   res = false;
	   cout<<boolalpha<<res<<endl;
   }
   return 0;
      
}
