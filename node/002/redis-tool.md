# redis-tool


### 查看Redis链接top
```

/usr/bin/redis-cli -h 127.0.0.1 -a "pwd"   -p 6544 client list 
    | awk '{print $1}'
    | cut -d = -f 2
    | cut -d : -f 1 
    | sort 
    | uniq -c 
    | sort -rn 
    | awk '{"host " $2 
    | getline h; print $1 "\t" $2 "\t" h;}'
    | awk '{print $1 "\t" $2 "\t" $7}'

```