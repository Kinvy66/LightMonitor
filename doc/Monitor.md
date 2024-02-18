# Linux 运行状态


## CPU 负载
`/proc/loadavg` 文件是负载信息  
```shell
cat /proc/loadavg
0.05 0.12 0.16 1/1132 74056
```
输出的信息：
- `load_avg_1` (0.05): 1分钟平均负载
- `load_avg_3` (0.12): 5分钟平均负载
- `load_avg_15` (0.16): 15分钟平均负载
- `nr_running`  (1): 在采样时刻，运行队列的任务的数目，与/proc/stat的procs_running表示相同意思
- `nr_threads` (1132) 在采样时刻，系统中活跃的任务的个数（不包括运行已经结束的任务）
- `last_pid` (74056) 最大的pid值，包括轻量级进程，即线程。

注意： linux系统是5秒钟进行一次Load采样


## CPU 中断
`/proc/softirqs` 中断信息

```shell
cat /proc/softirqs
                CPU0       CPU1       CPU2       CPU3       CPU4       CPU5       CPU6       CPU7       CPU8       CPU9       CPU10      CPU11      CPU12      CPU13      CPU14      CPU15      CPU16      CPU17      CPU18      CPU19
      HI:          0          0          0          0          0          0          0          0          0          0          0          0          0          0          0          0          0          0          0          0
   TIMER:      43499      29994      89750      32804      86504      34460      53098      14451      65400      23982      52553      18651      45055      59468      51404      16749      87482      20372      67927      17879
  NET_TX:         15         27         28         24         22         18         23         16         16          9         13          9         10          3         17          4         19          9         15          5
  NET_RX:      22016      21594      34841      26070      31574      23363      29023      24989      33462      21611      34326      24113      32842      23416      33207      27995      35554      20712      36783      25925
   BLOCK:      14277      14309      11214      14026      14398       2905      11671       2138       8829       1754       6233        656       4548       2344       2731        185       2591        704       2578        622
IRQ_POLL:          0          0          0          0          0          0          0          0          0          0          0          0          0          0          0          0          0          0          0          0
 TASKLET:    1582975     439540     401925     436326     429862          6          1          0          3          0          3          1          0          0          1          0          1          2         29          8
   SCHED:     192818     102746     163805      84220     173530      85086     134072      39972     162387      58140     139249      44304     141953      91239     162486      55504     158594      55817     154936      50286
 HRTIMER:          0          0          0          0          6          0          0          0          0          0          0          0          0          0          0          0          0         14          7        655
     RCU:     165780     104168     142165      97417     159510      83657     144791      53027     156479      74976     145472      54551     155690      86801     212965      78465     184102      88838     198547      71643
```

- HI: 
- TIMER: 定时器中断
- NET_TX: 网络中断TX
- NET_RX: 网络中断RX
- BLOCK: 块设备
- IRQ_POLL: 
- TASKLET:
- SCHED: 调度
- HRTIMER: 高精度定时器
- RCU: RCU锁


## CPU 状态
`/proc/stat`

```shell
cat /proc/stat
//CPU指标: user, nice, system, idle, iowait, irq, softirq
cpu  135006 518 84087 76628509 516538 0 11591 0 0 0
cpu0 7216 2 5276 3814812 39702 0 7348 0 0 0
cpu1 5619 0 3664 3810047 49569 0 1722 0 0 0
cpu2 7414 64 5168 3812659 42233 0 780 0 0 0
cpu3 5473 65 4066 3809413 49748 0 645 0 0 0
cpu4 6631 32 5502 3807279 48379 0 527 0 0 0
cpu5 5309 17 4144 3846730 13221 0 144 0 0 0
cpu6 6558 12 5245 3816626 39443 0 54 0 0 0
cpu7 3834 36 1830 3855360 8941 0 51 0 0 0
cpu8 7154 80 7916 3818451 34597 0 37 0 0 0
cpu9 5436 22 2396 3849048 12678 0 49 0 0 0
cpu10 6729 64 5312 3825482 30350 0 31 0 0 0
cpu11 3712 3 1971 3854212 9916 0 23 0 0 0
cpu12 7697 0 4603 3828277 27709 0 21 0 0 0
cpu13 4024 0 1895 3855457 8529 0 27 0 0 0
cpu14 11319 1 6424 3821262 24784 0 32 0 0 0
cpu15 6126 0 2506 3851596 9636 0 18 0 0 0
cpu16 11180 98 5398 3826275 24922 0 22 0 0 0
cpu17 9122 22 2565 3848138 9919 0 26 0 0 0
cpu18 9503 0 5920 3825525 21774 0 21 0 0 0
cpu19 4950 0 2286 3851850 10479 0 13 0 0 0
intr 24869675 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 83396 0 166 1 25 201 0 3 0 3 0 1396872 0 1258 0 2275011 0 1789 0 87 0 87 0 547 0 95 0 95 0 130 0 3 0 3 0 134194 0 134 0 4980 0 167 0 3 0 3 0 41095 0 3 0 410712 0 887 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
ctxt 87918153
btime 1708036447
processes 104685
procs_running 1
procs_blocked 0
softirq 9891163 0 939637 315 576799 125085 0 3386978 2328045 682 2533622
```


- user：到目前为止，CPU上nice值不大于0的用户态任务的运行时间
- nice：到目前为止，CPU上nice值大于0的用户态任务的运行时间
- system：到目前为止，CPU上内核态的运行时间。包括用户态任务系统调用、异常等陷入内核消耗时间，也包括内核线程消耗的时间； 但是不包括中断和软中断的执行时间。
- idle：到目前为止，处于idle任务的时间。不包括CPU上因为任务IO阻塞导致CPU上没有任务可运行、处于idle状态的时间。
- iowait: 到目前为止，由于CPU上任务IO阻塞导致CPU无可运行任务、处于idle的时间。需要强调的是，iowait是在CPU处于idle状态下的一种特殊情况的时间，与上面的“idle”列互补构成CPU上真正处于idle的时间。
- irq：到目前为止，CPU进入到中断处理的时间(在没有使能CONFIG_IRQ_TIME_ACCOUNTING的情况下，大部分架构实际上无法记录到该项，见下面的分析)。
- softirq：到目前为止，CPU处理软中断的时间，包括softirqd中处理软中断的时间。



## 内存信息
`/proc/meminfo`

```shell
cat /proc/meminfo
MemTotal:       16378224 kB
MemFree:        14596192 kB
MemAvailable:   14688652 kB
Buffers:           11468 kB
Cached:           292092 kB
SwapCached:        13592 kB
Active:           274104 kB
Inactive:         718628 kB
Active(anon):     155660 kB
Inactive(anon):   534460 kB
Active(file):     118444 kB
Inactive(file):   184168 kB
Unevictable:           0 kB
Mlocked:               0 kB
SwapTotal:       4194304 kB
SwapFree:        1960344 kB
Dirty:                36 kB
Writeback:             0 kB
AnonPages:        675992 kB
Mapped:           163268 kB
Shmem:               924 kB
KReclaimable:      76536 kB
Slab:             282172 kB
SReclaimable:      76536 kB
SUnreclaim:       205636 kB
KernelStack:       18496 kB
PageTables:        33484 kB
NFS_Unstable:          0 kB
Bounce:                0 kB
WritebackTmp:          0 kB
CommitLimit:    12383416 kB
Committed_AS:    5783456 kB
VmallocTotal:   34359738367 kB
VmallocUsed:      118384 kB
VmallocChunk:          0 kB
Percpu:            17184 kB
AnonHugePages:     96256 kB
ShmemHugePages:        0 kB
ShmemPmdMapped:        0 kB
FileHugePages:         0 kB
FilePmdMapped:         0 kB
HugePages_Total:       0
HugePages_Free:        0
HugePages_Rsvd:        0
HugePages_Surp:        0
Hugepagesize:       2048 kB
Hugetlb:               0 kB
DirectMap4k:      351232 kB
DirectMap2M:    12230656 kB
DirectMap1G:    13631488 kB
```

## 网络
```shell
cat /proc/net/dev
Inter-|   Receive                                                |  Transmit
 face |bytes    packets errs drop fifo frame compressed multicast|bytes    packets errs drop fifo colls carrier compressed
    lo:  119592     824    0    0    0     0          0         0   119592     824    0    0    0     0       0          0
  eth0:     140       2    0    0    0     0          0         2        0       0    0    0    0     0       0          0
loopback0: 11340335    9913    0    0    0     0          0        10   135271    1981    0    0    0     0       0          0
  eth3: 32886355   28757    0    0    0     0          0      2444   513779    5996    0    0    0     0       0          0
  eth1:       0       0    0    0    0     0          0         0        0       0    0    0    0     0       0          0
  eth2:       0       0    0    0    0     0          0         0        0       0    0    0    0     0       0          0
```


- bytes: The total number of bytes of data transmitted or received by the interface.（接口发送或接收的数据的总字节数）
- packets: The total number of packets of data transmitted or received by the interface.（接口发送或接收的数据包总数）
- errs: The total number of transmit or receive errors detected by the device driver.（由设备驱动程序检测到的发送或接收错误的总数）
- drop: The total number of packets dropped by the device driver.（设备驱动程序丢弃的数据包总数）
- fifo: The number of FIFO buffer errors.（FIFO缓冲区错误的数量）
- frame: The number of packet framing errors.（分组帧错误的数量）
- colls: The number of collisions detected on the interface.（接口上检测到的冲突数）
- compressed: The number of compressed packets transmitted or received by the device driver. (This appears to be unused in the 2.2.15 kernel.)（设备驱动程序发送或接收的压缩数据包数）
- carrier: The number of carrier losses detected by the device driver.（由设备驱动程序检测到的载波损耗的数量）
- multicast: The number of multicast frames transmitted or received by the device driver.（设备驱动程序发送或接收的多播帧数）
