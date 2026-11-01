buckets[index][i].key==key
buckets[index][i].count++;
Entry tmp;
tmp.key=key;tmp.count=1;
buckets[index].push_back(tmp);
return ;
