# Linux files Explanation

## /proc/cmdline

Arguments passed to the Linux kernel at boot time.  Often done via a boot manager such as lilo(8) or grub(8).
`Ex`
> cat /proc/cmdline
>> BOOT_IMAGE=/boot/vmlinuz-5.11.0-40-generic ro quiet 

## /proc/cpuinfo

This is a collection of `CPU` and `system architecture` dependent items, for each supported `architecture` a different list.

`Ex`
>cat /proc/cpuinfo
>>processor       : 0\
vendor_id       : AuthenticAMD\
cpu family      : 23\
model           : 113\
model name      : AMD Ryzen 5 3600 6-Core Processor\
stepping        : 0\
microcode       : 0x8701021\
cpu MHz         : 3600.000\
cache size      : 512 KB\
physical id     : 0\
siblings        : 12\
core id         : 0\
cpu cores       : 6\
apicid          : 0\
initial apicid  : 0\
fpu             : yes\
fpu_exception   : yes\
cpuid level     : 16\
wp              : yes\
flags           : fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx mmxext fxsr_opt pdpe1gb rdtscp lm constant_tsc rep_good nopl nonstop_tsc cpuid extd_apicid aperfmperf pni pclmulqdq monitor ssse3 fma cx16 sse4_1 sse4_2 movbe popcnt aes xsave avx f16c rdrand lahf_lm cmp_legacy svm extapic cr8_legacy abm sse4a misalignsse 3dnowprefetch osvw ibs skinit wdt tce topoext perfctr_core perfctr_nb bpext perfctr_llc mwaitx cpb cat_l3 cdp_l3 hw_pstate sme ssbd mba sev ibpb stibp vmmcall sev_es fsgsbase bmi1 avx2 smep bmi2 cqm rdt_a rdseed adx smap clflushopt clwb sha_ni xsaveopt xsavec xgetbv1 xsaves cqm_llc cqm_occup_llc cqm_mbm_total cqm_mbm_local clzero irperf xsaveerptr rdpru wbnoinvd arat npt lbrv svm_lock nrip_save tsc_scale vmcb_clean flushbyasid decodeassists pausefilter pfthreshold avic v_vmsave_vmload vgif umip rdpid overflow_recov succor smca\
bugs            : sysret_ss_attrs spectre_v1 spectre_v2 spec_store_bypass\
bogomips        : 7200.19\
TLB size        : 3072 4K pages\
clflush size    : 64\
cache_alignment : 64\
address sizes   : 43 bits physical, 48 bits virtual\
power management: ts ttp tm hwpstate cpb eff_freq_ro [13] [14]\
>>processor       : 1\
vendor_id       : AuthenticAMD\
cpu family      : 23\
model           : 113\
model name      : AMD Ryzen 5 3600 6-Core Processor\
stepping        : 0\
microcode       : 0x8701021\
cpu MHz         : 2243.089\
cache size      : 512 KB\
physical id     : 0\
siblings        : 12\
core id         : 1\
cpu cores       : 6\
apicid          : 2\
initial apicid  : 2\
fpu             : yes\
fpu_exception   : yes\
cpuid level     : 16\
wp              : yes\
flags           : fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx mmxext fxsr_opt pdpe1gb rdtscp lm constant_tsc rep_good nopl nonstop_tsc cpuid extd_apicid aperfmperf pni pclmulqdq monitor ssse3 fma cx16 sse4_1 sse4_2 movbe popcnt aes xsave avx f16c rdrand lahf_lm cmp_legacy svm extapic cr8_legacy abm sse4a misalignsse 3dnowprefetch osvw ibs skinit wdt tce topoext perfctr_core perfctr_nb bpext perfctr_llc mwaitx cpb cat_l3 cdp_l3 hw_pstate sme ssbd mba sev ibpb stibp vmmcall sev_es fsgsbase bmi1 avx2 smep bmi2 cqm rdt_a rdseed adx smap clflushopt clwb sha_ni xsaveopt xsavec xgetbv1 xsaves cqm_llc cqm_occup_llc cqm_mbm_total cqm_mbm_local clzero irperf xsaveerptr rdpru wbnoinvd arat npt lbrv svm_lock nrip_save tsc_scale vmcb_clean flushbyasid decodeassists pausefilter pfthreshold avic v_vmsave_vmload vgif umip rdpid overflow_recov succor smca\
bugs            : sysret_ss_attrs spectre_v1 spectre_v2 spec_store_bypass\
bogomips        : 7200.19\
TLB size        : 3072 4K pages\
clflush size    : 64\
cache_alignment : 64\
address sizes   : 43 bits physical, 48 bits virtual\
power management: ts ttp tm hwpstate cpb eff_freq_ro [13] [14]\
processor       : 2\
...

## /proc/pid/status

Provides much of the information in /proc/[pid]/stat and /proc/[pid]/statm in a format that's easier for humans to parse.

`Ex`
cat /proc/1/status
>>Name:   systemd\
Umask:  0000\
State:  S (sleeping)\
Tgid:   1\
Ngid:   0\
Pid:    1\
PPid:   0\
TracerPid:      0\
Uid:    0       0       0       0\
Gid:    0       0       0       0\
FDSize: 512\
Groups:  \
NStgid: 1\
NSpid:  1\
NSpgid: 1\
NSsid:  1\
VmPeak:   230456 kB\
VmSize:   166464 kB\
VmLck:         0 kB\
VmPin:         0 kB\
VmHWM:     13016 kB\
VmRSS:     12996 kB\
RssAnon:            5140 kB\
RssFile:            7856 kB\
RssShmem:              0 kB\
VmData:    20364 kB\
VmStk:      1036 kB\
VmExe:       844 kB\
VmLib:      8180 kB\
VmPTE:        88 kB\
VmSwap:        0 kB\
HugetlbPages:          0 kB\
CoreDumping:    0\
THP_enabled:    1\
Threads:        1\
SigQ:   0/63428\
SigPnd: 0000000000000000\
ShdPnd: 0000000000000000\
SigBlk: 7be3c0fe28014a03\
SigIgn: 0000000000001000\
SigCgt: 00000001800004ec\
CapInh: 0000000000000000\
CapPrm: 000001ffffffffff\
CapEff: 000001ffffffffff\
CapBnd: 000001ffffffffff\
CapAmb: 0000000000000000\
NoNewPrivs:     0\
Seccomp:        0\
Seccomp_filters:        0\
Speculation_Store_Bypass:       thread vulnerable\
SpeculationIndirectBranch:      conditional enabled\
Cpus_allowed:   ffffffff\
Cpus_allowed_list:      0-31\
Mems_allowed:   00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000001\
Mems_allowed_list:      0\
voluntary_ctxt_switches:        23803\
nonvoluntary_ctxt_switches:     532\

## /proc/stat

kernel/system statistics.  Varies with architecture.
Common entries include `cpu`:\
    `user`   (1) Time spent in user mode.\
    `nice`   (2) Time spent in user mode with low priority (nice).\
    `system` (3) Time spent in system mode.\
    `idle`   (4) Time spent in the idle task.  This value should be USER_HZ times the second entry in the /proc/uptime pseudo-file.\
    `iowait` (since Linux 2.5.41) (5) Time waiting for I/O to complete.  This value is not reliable, for the following reasons:\
        1. The CPU will not wait for I/O to
            complete; iowait is the time that a task
            is waiting for I/O to complete.  When a
            CPU goes into idle state for outstanding
            task I/O, another task will be scheduled
            on this CPU.\
        2. On a multi-core CPU, the task waiting for
            I/O to complete is not running on any
            CPU, so the iowait of each CPU is
            difficult to calculate.\
        3. The value in this field may decrease in
            certain conditions.\
    `irq` (since Linux 2.6.0) (6) Time servicing interrupts.\
    `softirq` (since Linux 2.6.0) (7) Time servicing softirqs.\
    `steal` (since Linux 2.6.11) (8) Stolen time, which is the time spent in other operating systems when running in a virtualized environment\
    `guest` (since Linux 2.6.24) (9) Time spent running a virtual CPU for guest operating systems under the control of the Linux kernel.\
    `guest_nice` (since Linux 2.6.33) (10) Time spent running a niced guest (virtual CPU for guest operating systems under the control of the Linux kernel).\
`page`: 5741 1808\
The number of pages the system paged in and the
number that were paged out (from disk).\
`swap`: 1 0\
The number of swap pages that have been brought in
and out.\
`intr`: 1462898\
This line shows counts of interrupts serviced since
boot time, for each of the possible system
interrupts.  The first column is the total of all
interrupts serviced including unnumbered
architecture specific interrupts; each subsequent
column is the total for that particular numbered
interrupt.  Unnumbered interrupts are not shown,
only summed into the total.\
`disk_io`:\
(2,0):(31,30,5764,1,2) (3,0):...
(major,disk_idx):(noinfo, read_io_ops, blks_read,
write_io_ops, blks_written)
(Linux 2.4 only)\
`ctxt` 115315\
The number of context switches that the system
underwent.\
`btime` 769041601\
boot time, in seconds since the Epoch, 1970-01-01
00:00:00 +0000 (UTC).\
`processes` 86031\
Number of forks since boot.\
`procs_running` 6\
Number of processes in runnable state.  (Linux
2.5.45 onward.)\
`procs_blocked` 2\
Number of processes blocked waiting for I/O to
complete.  (Linux 2.5.45 onward.)\
`softirq` 229245889 94 60001584 13619 5175704 2471304 28
51212741 59130143 0 51240672\
This line shows the number of softirq for all CPUs.
The first column is the total of all softirqs and
each subsequent column is the total for particular
softirq.  (Linux 2.6.31 onward.)\
`Ex`
>cat /proc/stat
>> cpu  4981016 7840 3142404 32788515 69354 0 59595 0 0 0\
cpu0 411387 501 345541 31414865 57388 0 35691 0 0 0\
cpu1 397696 686 255176 124983 922 0 12077 0 0 0\
cpu2 456166 644 255971 124116 1285 0 4936 0 0 0\
cpu3 459107 856 251151 125209 951 0 2263 0 0 0\
cpu4 383435 744 253847 125034 885 0 1225 0 0 0\
cpu5 423192 557 253455 125532 663 0 773 0 0 0\
cpu6 428558 498 255392 124881 875 0 759 0 0 0\
cpu7 383180 557 260997 124748 1192 0 321 0 0 0\
cpu8 421742 1208 255058 124209 1623 0 744 0 0 0\
cpu9 416286 532 245426 125230 1094 0 298 0 0 0\
cpu10 376749 622 256780 124619 1360 0 250 0 0 0\
cpu11 423514 431 253606 125083 1109 0 254 0 0 0\
intr 1244358743 34 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2263481 0 410 30893 288 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 7134 0 0 0 0 0 0 0 0 0 0 4101921 194099 158348 163303 233549 158798 185312 187230 154832 116159 124511 116567 132192 9 10767646 0 0 11 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\
ctxt 10366682163\
btime 1637139742\
processes 651892\
procs_running 2\
procs_blocked 0\
softirq 207626501 4686928 18978649 59 2486479 2335785 22 1446231 111154482 19033 66518833\

## /proc/`pid`/stat

Status information about the process.  This is used by
              ps(1).  It is defined in the kernel source file
              fs/proc/array.c.

              The fields, in order, with their proper scanf(3) format
              specifiers, are listed below.  Whether or not certain of
              these fields display valid information is governed by a
              ptrace access mode PTRACE_MODE_READ_FSCREDS |
              PTRACE_MODE_NOAUDIT check (refer to ptrace(2)).  If the
              check denies access, then the field value is displayed as
              0.  The affected fields are indicated with the marking
              [PT].

              (1) pid  %d
                     The process ID.

              (2) comm  %s
                     The filename of the executable, in parentheses.
                     Strings longer than TASK_COMM_LEN (16) characters
                     (including the terminating null byte) are silently
                     truncated.  This is visible whether or not the
                     executable is swapped out.

              (3) state  %c
                     One of the following characters, indicating process
                     state:

                     R  Running

                     S  Sleeping in an interruptible wait

                     D  Waiting in uninterruptible disk sleep

                     Z  Zombie

                     T  Stopped (on a signal) or (before Linux 2.6.33)
                        trace stopped

                     t  Tracing stop (Linux 2.6.33 onward)

                     W  Paging (only before Linux 2.6.0)

                     X  Dead (from Linux 2.6.0 onward)

                     x  Dead (Linux 2.6.33 to 3.13 only)

                     K  Wakekill (Linux 2.6.33 to 3.13 only)

                     W  Waking (Linux 2.6.33 to 3.13 only)

                     P  Parked (Linux 3.9 to 3.13 only)

              (4) ppid  %d
                     The PID of the parent of this process.

              (5) pgrp  %d
                     The process group ID of the process.

              (6) session  %d
                     The session ID of the process.

              (7) tty_nr  %d
                     The controlling terminal of the process.  (The
                     minor device number is contained in the combination
                     of bits 31 to 20 and 7 to 0; the major device
                     number is in bits 15 to 8.)

              (8) tpgid  %d
                     The ID of the foreground process group of the
                     controlling terminal of the process.

              (9) flags  %u
                     The kernel flags word of the process.  For bit
                     meanings, see the PF_* defines in the Linux kernel
                     source file include/linux/sched.h.  Details depend
                     on the kernel version.

                     The format for this field was %lu before Linux 2.6.

              (10) minflt  %lu
                     The number of minor faults the process has made
                     which have not required loading a memory page from
                     disk.

              (11) cminflt  %lu
                     The number of minor faults that the process's
                     waited-for children have made.

              (12) majflt  %lu
                     The number of major faults the process has made
                     which have required loading a memory page from
                     disk.

              (13) cmajflt  %lu
                     The number of major faults that the process's
                     waited-for children have made.

              (14) utime  %lu
                     Amount of time that this process has been scheduled
                     in user mode, measured in clock ticks (divide by
                     sysconf(_SC_CLK_TCK)).  This includes guest time,
                     guest_time (time spent running a virtual CPU, see
                     below), so that applications that are not aware of
                     the guest time field do not lose that time from
                     their calculations.

              (15) stime  %lu
                     Amount of time that this process has been scheduled
                     in kernel mode, measured in clock ticks (divide by
                     sysconf(_SC_CLK_TCK)).

              (16) cutime  %ld
                     Amount of time that this process's waited-for
                     children have been scheduled in user mode, measured
                     in clock ticks (divide by sysconf(_SC_CLK_TCK)).
                     (See also times(2).)  This includes guest time,
                     cguest_time (time spent running a virtual CPU, see
                     below).

              (17) cstime  %ld
                     Amount of time that this process's waited-for
                     children have been scheduled in kernel mode,
                     measured in clock ticks (divide by
                     sysconf(_SC_CLK_TCK)).

              (18) priority  %ld
                     (Explanation for Linux 2.6) For processes running a
                     real-time scheduling policy (policy below; see
                     sched_setscheduler(2)), this is the negated
                     scheduling priority, minus one; that is, a number
                     in the range -2 to -100, corresponding to real-time
                     priorities 1 to 99.  For processes running under a
                     non-real-time scheduling policy, this is the raw
                     nice value (setpriority(2)) as represented in the
                     kernel.  The kernel stores nice values as numbers
                     in the range 0 (high) to 39 (low), corresponding to
                     the user-visible nice range of -20 to 19.

                     Before Linux 2.6, this was a scaled value based on
                     the scheduler weighting given to this process.

              (19) nice  %ld
                     The nice value (see setpriority(2)), a value in the
                     range 19 (low priority) to -20 (high priority).

              (20) num_threads  %ld
                     Number of threads in this process (since Linux
                     2.6).  Before kernel 2.6, this field was hard coded
                     to 0 as a placeholder for an earlier removed field.

              (21) itrealvalue  %ld
                     The time in jiffies before the next SIGALRM is sent
                     to the process due to an interval timer.  Since
                     kernel 2.6.17, this field is no longer maintained,
                     and is hard coded as 0.

              (22) starttime  %llu
                     The time the process started after system boot.  In
                     kernels before Linux 2.6, this value was expressed
                     in jiffies.  Since Linux 2.6, the value is
                     expressed in clock ticks (divide by
                     sysconf(_SC_CLK_TCK)).

                     The format for this field was %lu before Linux 2.6.

              (23) vsize  %lu
                     Virtual memory size in bytes.

              (24) rss  %ld
                     Resident Set Size: number of pages the process has
                     in real memory.  This is just the pages which count
                     toward text, data, or stack space.  This does not
                     include pages which have not been demand-loaded in,
                     or which are swapped out.  This value is
                     inaccurate; see /proc/[pid]/statm below.

              (25) rsslim  %lu
                     Current soft limit in bytes on the rss of the
                     process; see the description of RLIMIT_RSS in
                     getrlimit(2).

              (26) startcode  %lu  [PT]
                     The address above which program text can run.

              (27) endcode  %lu  [PT]
                     The address below which program text can run.

              (28) startstack  %lu  [PT]
                     The address of the start (i.e., bottom) of the
                     stack.

              (29) kstkesp  %lu  [PT]
                     The current value of ESP (stack pointer), as found
                     in the kernel stack page for the process.

              (30) kstkeip  %lu  [PT]
                     The current EIP (instruction pointer).

              (31) signal  %lu
                     The bitmap of pending signals, displayed as a
                     decimal number.  Obsolete, because it does not
                     provide information on real-time signals; use
                     /proc/[pid]/status instead.

              (32) blocked  %lu
                     The bitmap of blocked signals, displayed as a
                     decimal number.  Obsolete, because it does not
                     provide information on real-time signals; use
                     /proc/[pid]/status instead.

              (33) sigignore  %lu
                     The bitmap of ignored signals, displayed as a
                     decimal number.  Obsolete, because it does not
                     provide information on real-time signals; use
                     /proc/[pid]/status instead.

              (34) sigcatch  %lu
                     The bitmap of caught signals, displayed as a
                     decimal number.  Obsolete, because it does not
                     provide information on real-time signals; use
                     /proc/[pid]/status instead.

              (35) wchan  %lu  [PT]
                     This is the "channel" in which the process is
                     waiting.  It is the address of a location in the
                     kernel where the process is sleeping.  The
                     corresponding symbolic name can be found in
                     /proc/[pid]/wchan.

              (36) nswap  %lu
                     Number of pages swapped (not maintained).

              (37) cnswap  %lu
                     Cumulative nswap for child processes (not
                     maintained).

              (38) exit_signal  %d  (since Linux 2.1.22)
                     Signal to be sent to parent when we die.

              (39) processor  %d  (since Linux 2.2.8)
                     CPU number last executed on.

              (40) rt_priority  %u  (since Linux 2.5.19)
                     Real-time scheduling priority, a number in the
                     range 1 to 99 for processes scheduled under a real-
                     time policy, or 0, for non-real-time processes (see
                     sched_setscheduler(2)).

              (41) policy  %u  (since Linux 2.5.19)
                     Scheduling policy (see sched_setscheduler(2)).
                     Decode using the SCHED_* constants in
                     linux/sched.h.

                     The format for this field was %lu before Linux
                     2.6.22.

              (42) delayacct_blkio_ticks  %llu  (since Linux 2.6.18)
                     Aggregated block I/O delays, measured in clock
                     ticks (centiseconds).

              (43) guest_time  %lu  (since Linux 2.6.24)
                     Guest time of the process (time spent running a
                     virtual CPU for a guest operating system), measured
                     in clock ticks (divide by sysconf(_SC_CLK_TCK)).

              (44) cguest_time  %ld  (since Linux 2.6.24)
                     Guest time of the process's children, measured in
                     clock ticks (divide by sysconf(_SC_CLK_TCK)).

              (45) start_data  %lu  (since Linux 3.3)  [PT]
                     Address above which program initialized and
                     uninitialized (BSS) data are placed.

              (46) end_data  %lu  (since Linux 3.3)  [PT]
                     Address below which program initialized and
                     uninitialized (BSS) data are placed.

              (47) start_brk  %lu  (since Linux 3.3)  [PT]
                     Address above which program heap can be expanded
                     with brk(2).

              (48) arg_start  %lu  (since Linux 3.5)  [PT]
                     Address above which program command-line arguments
                     (argv) are placed.

              (49) arg_end  %lu  (since Linux 3.5)  [PT]
                     Address below program command-line arguments (argv)
                     are placed.

              (50) env_start  %lu  (since Linux 3.5)  [PT]
                     Address above which program environment is placed.

              (51) env_end  %lu  (since Linux 3.5)  [PT]
                     Address below which program environment is placed.

              (52) exit_code  %d  (since Linux 3.5)  [PT]
                     The thread's exit status in the form reported by
                     waitpid(2).
`Ex`
> cat /proc/1/stat
>> 1 (systemd) S 0 1 1 0 -1 4194560 27487 156047 157 1136 40 71 224 223 20 0 1 0 10 168890368 2837 18446744073709551615 1 1 0 0 0 0 671173123 4096 1260 0 0 0 17 11 0 0 1028 0 0 0 0 0 0 0 0 0 0

## /proc/uptime

 This file contains two numbers (values in seconds): the uptime of the system (including time spent in suspend) and the amount of time spent in the idle process.\
`Ex`
> cat /proc/uptime
>> 13720.48 161783.35

## /proc/meminfo

This file reports statistics about memory usage on the
              system.  It is used by free(1) to report the amount of
              free and used memory (both physical and swap) on the
              system as well as the shared memory and buffers used by
              the kernel.  Each line of the file consists of a parameter
              name, followed by a colon, the value of the parameter, and
              an option unit of measurement (e.g., "kB").  The list
              below describes the parameter names and the format
              specifier required to read the field value.  Except as
              noted below, all of the fields have been present since at
              least Linux 2.6.0.  Some fields are displayed only if the
              kernel was configured with various options; those
              dependencies are noted in the list.
`Ex`
> cat /proc/meminfo
>> MemTotal:       16306556 kB\
>> MemFree:         8138764 kB\
>> MemAvailable:   11309960 kB\
>> Buffers:          235612 kB\
>> Cached:          3239992 kB\
>> SwapCached:            0 kB\
>> Active:          1134700 kB\
>> Inactive:        6410788 kB\
>> Active(anon):      11788 kB\
>> Inactive(anon):  4192196 kB\
>> Active(file):    1122912 kB\
>> Inactive(file):  2218592 kB\
>> Unevictable:          64 kB\
>> Mlocked:              64 kB\
>> SwapTotal:       2097148 kB\
>> SwapFree:        2097148 kB\
>> Dirty:               388 kB\
>> Writeback:             0 kB\
>> AnonPages:       4070036 kB\
>> Mapped:           944360 kB\
>> Shmem:            212960 kB\
>> KReclaimable:     162320 kB\
>> Slab:             325404 kB\
>> SReclaimable:     162320 kB\
>> SUnreclaim:       163084 kB\
>> KernelStack:       26320 kB\
>> PageTables:        61676 kB\
>> NFS_Unstable:          0 kB\
>> Bounce:                0 kB\
>> WritebackTmp:          0 kB\
>> CommitLimit:    10250424 kB\
>> Committed_AS:   17107468 kB\
>> VmallocTotal:   34359738367 kB\
>> VmallocUsed:       61952 kB\
>> VmallocChunk:          0 kB\
>> Percpu:            32384 kB\
>> HardwareCorrupted:     0 kB\
>> AnonHugePages:      2048 kB\
>> ShmemHugePages:        0 kB\
>> ShmemPmdMapped:        0 kB\
>> FileHugePages:         0 kB\
>> FilePmdMapped:         0 kB\
>> HugePages_Total:       0\
>> HugePages_Free:        0\
>> HugePages_Rsvd:        0\
>> HugePages_Surp:        0\
>> Hugepagesize:       2048 kB\
>> Hugetlb:               0 kB\
>> DirectMap4k:      510568 kB\
>> DirectMap2M:     7802880 kB\
>> DirectMap1G:     9437184 kB\

## /proc/version

`Ex`
> cat /proc/version
>> Linux version 5.11.0-40-generic (buildd@lgw01-amd64-048) (gcc (Ubuntu 10.3.0-1ubuntu1) 10.3.0, GNU ld (GNU Binutils for Ubuntu) 2.36.1) #44-Ubuntu SMP Wed Oct 20 16:16:42 UTC 2021

## /etc/os-release

`Ex`
> cat /proc/os-release
>> NAME="Ubuntu"\
>> VERSION="21.04 (Hirsute Hippo)"\
>> ID=ubuntu\
>> ID_LIKE=debian\
>> PRETTY_NAME="Ubuntu 21.04"\
>> VERSION_ID="21.04"\
>> HOME_URL="https://www.ubuntu.com/"\
>> SUPPORT_URL="https://help.ubuntu.com/"\
>> BUG_REPORT_URL="https://bugs.launchpad.net/ubuntu/"\
>> PRIVACY_POLICY_URL="https://www.ubuntu.com/legal/terms-and-policies/privacy-policy"\
>> VERSION_CODENAME=hirsute\
>> UBUNTU_CODENAME=hirsute\

## /etc/passwd

Each line in the file has seven fields delimited by colons that contain the following information:

* User name.
* Encrypted password (x means that the password is stored in the /etc/shadow file).
* User ID number (UID).
* User’s group ID number (GID).
* Full name of the user (GECOS).
* User home directory.
* Login shell (defaults to /bin/bash).

`Ex`
> cat /etc/passwd
>> root:x:0:0:root:/root:/bin/bash\
daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin\
bin:x:2:2:bin:/bin:/usr/sbin/nologin\
sys:x:3:3:sys:/dev:/usr/sbin/nologin

## other commands

### jiffies

to find the number of jiffies per second (HZ) for our system we use:
> grep 'CONFIG_HZ=' /boot/config-$(uname -r)
>> CONFIG_HZ=250

this means that the one jiffy is 1/250=4ms, it means that the system is configured to interrupt every 4ms.
jiffeis is refered to as software clock.

### /proc/timer_list

This read-only file exposes a list of all currently pending (high-resolution) timers, all clock-event sources, and their parameters in a human-readable form.

`Ex`
> cat /proc/timer_list
> > part of the output

```
cpu: 11
 clock 0:
  .base:       ffff9f118ecdf240
  .index:      0
  .resolution: 1 nsecs
  .get_time:   ktime_get
  .offset:     0 nsecs
active timers:
 #0: <ffff9f118ecdf740>, tick_sched_timer, S:01
 # expires at 15515578273147-15515578273147 nsecs [in 6880652 to 6880652 nsecs]
 #1: <ffffb79c44dcfe90>, hrtimer_wakeup, S:01
 # expires at 15516052052973-15516052102973 nsecs [in 480660478 to 480710478 nsecs]
 #2: <ffffb79c4424fa08>, hrtimer_wakeup, S:01
 # expires at 15516127282666-15516127841665 nsecs [in 555890171 to 556449170 nsecs]
 #3: <ffff9f118ecdf9a0>, watchdog_timer_fn, S:01
 # expires at 15516238273147-15516238273147 nsecs [in 666880652 to 666880652 nsecs]
 #4: <ffffb79c4562fe90>, hrtimer_wakeup, S:01
 # expires at 15516322037902-15516322087902 nsecs [in 750645407 to 750695407 nsecs]
 #5: <ffffb79c42347db8>, hrtimer_wakeup, S:01
 # expires at 15516566795822-15516566845822 nsecs [in 995403327 to 995453327 nsecs]
 #6: <ffffb79c44427d58>, hrtimer_wakeup, S:01
 # expires at 15516566418167-15516569449166 nsecs [in 995025672 to 998056671 nsecs]
 #7: <ffffb79c445c7db8>, hrtimer_wakeup, S:01
 # expires at 15517781991689-15517782041689 nsecs [in 2210599194 to 2210649194 nsecs]
 #8: <ffffb79c44de7db8>, hrtimer_wakeup, S:01
 # expires at 15518562595006-15518562645006 nsecs [in 2991202511 to 2991252511 nsecs]
 #9: <ffffb79c45687db8>, hrtimer_wakeup, S:01
 # expires at 15519781401183-15519781451183 nsecs [in 4210008688 to 4210058688 nsecs]
 #10: <ffffb79c441cfd88>, hrtimer_wakeup, S:01
 # expires at 15519866898035-15519886649034 nsecs [in 4295505540 to 4315256539 nsecs]
 #11: <ffffb79c42377a08>, hrtimer_wakeup, S:01
 # expires at 15525420876893-15525430876892 nsecs [in 9849484398 to 9859484397 nsecs]
 #12: <ffffb79c4575fdb8>, hrtimer_wakeup, S:01
 # expires at 15532939986601-15532940036601 nsecs [in 17368594106 to 17368644106 nsecs]
 #13: <ffffb79c4536fdb8>, hrtimer_wakeup, S:01
 # expires at 15533124703718-15533124753718 nsecs [in 17553311223 to 17553361223 nsecs]
 #14: <ffffb79c4390fa08>, hrtimer_wakeup, S:01
 # expires at 15539941236822-15539971206821 nsecs [in 24369844327 to 24399814326 nsecs]
 #15: <ffffb79c46227db8>, hrtimer_wakeup, S:01
 # expires at 15541802289771-15541802339771 nsecs [in 26230897276 to 26230947276 nsecs]
 #16: <ffffb79c42cb7db8>, hrtimer_wakeup, S:01
 # expires at 15541850927045-15541850977045 nsecs [in 26279534550 to 26279584550 nsecs]
 #17: <ffffb79c45637db8>, hrtimer_wakeup, S:01
 # expires at 15544003235644-15544003285644 nsecs [in 28431843149 to 28431893149 nsecs]
 #18: <ffffb79c4593fdb8>, hrtimer_wakeup, S:01
 # expires at 15544003298823-15544003348823 nsecs [in 28431906328 to 28431956328 nsecs]
 #19: <ffffb79c45607db8>, hrtimer_wakeup, S:01
 # expires at 15544003340192-15544003390192 nsecs [in 28431947697 to 28431997697 nsecs]
 #20: <ffffb79c446b7db8>, hrtimer_wakeup, S:01
 # expires at 15560124845766-15560124895766 nsecs [in 44553453271 to 44553503271 nsecs]
 #21: <ffffb79c43c67db8>, hrtimer_wakeup, S:01
 # expires at 16104107279486-16104107329486 nsecs [in 588535886991 to 588535936991 nsecs]
 #22: <ffffb79c44f17d58>, hrtimer_wakeup, S:01
 # expires at 16122827957042-16122927957042 nsecs [in 607256564547 to 607356564547 nsecs]
 #23: <ffffb79c445bfd58>, hrtimer_wakeup, S:01
 # expires at 16553823420177-16553923420177 nsecs [in 1038252027682 to 1038352027682 nsecs]
 #24: <ffffb79c41babe68>, hrtimer_wakeup, S:01
 # expires at 18040801891347-18040801941347 nsecs [in 2525230498852 to 2525230548852 nsecs]
 #25: <ffffb79c423a7a08>, hrtimer_wakeup, S:01
 # expires at 21666000764123-21666100764123 nsecs [in 6150429371628 to 6150529371628 nsecs]
 clock 1:
  .base:       ffff9f118ecdf280
  .index:      1
  .resolution: 1 nsecs
  .get_time:   ktime_get_real
  .offset:     1637813884423152872 nsecs
active timers:
 #0: <ffffffffa1515580>, sync_timer_callback, S:01
 # expires at 1637829792500000000-1637829792500000000 nsecs [in 392505454633 to 392505454633 nsecs]
 clock 2:
  .base:       ffff9f118ecdf2c0
  .index:      2
  .resolution: 1 nsecs
  .get_time:   ktime_get_boottime
  .offset:     0 nsecs
active timers:
 clock 3:
  .base:       ffff9f118ecdf300
  .index:      3
  .resolution: 1 nsecs
  .get_time:   ktime_get_clocktai
  .offset:     1637813884423152872 nsecs
active timers:
 clock 4:
  .base:       ffff9f118ecdf340
  .index:      4
  .resolution: 1 nsecs
  .get_time:   ktime_get
  .offset:     0 nsecs
active timers:
 clock 5:
  .base:       ffff9f118ecdf380
  .index:      5
  .resolution: 1 nsecs
  .get_time:   ktime_get_real
  .offset:     1637813884423152872 nsecs
active timers:
 clock 6:
  .base:       ffff9f118ecdf3c0
  .index:      6
  .resolution: 1 nsecs
  .get_time:   ktime_get_boottime
  .offset:     0 nsecs
active timers:
 clock 7:
  .base:       ffff9f118ecdf400
  .index:      7
  .resolution: 1 nsecs
  .get_time:   ktime_get_clocktai
  .offset:     1637813884423152872 nsecs
active timers:
  .expires_next   : 15515578273147 nsecs
  .hres_active    : 1
  .nr_events      : 503990
  .nr_retries     : 2506
  .nr_hangs       : 0
  .max_hang_time  : 0
  .nohz_mode      : 2
  .last_tick      : 15515574273147 nsecs
  .tick_stopped   : 0
  .idle_jiffies   : 4298771170
  .idle_calls     : 449769
  .idle_sleeps    : 449769
  .idle_entrytime : 15515574369826 nsecs
  .idle_waketime  : 15515571439654 nsecs
  .idle_exittime  : 15515571441994 nsecs
  .idle_sleeptime : 15194516072764 nsecs
  .iowait_sleeptime: 103975479125 nsecs
  .last_jiffies   : 4298771171
  .next_timer     : 15517354273147
  .idle_expires   : 15517354273147 nsecs
jiffies: 4298771171

Tick Device: mode:     1
Broadcast device
Clock Event Device: hpet
 max_delta_ns:   149983003521
 min_delta_ns:   13410
 mult:           61496115
 shift:          32
 mode:           1
 next_event:     9223372036854775807 nsecs
 set_next_event: hpet_clkevt_set_next_event
 shutdown:       hpet_clkevt_set_state_shutdown
 periodic:       hpet_clkevt_set_state_periodic
 oneshot:        hpet_clkevt_set_state_oneshot
 resume:         hpet_clkevt_legacy_resume
 event_handler:  tick_handle_oneshot_broadcast

 retries:        0

tick_broadcast_mask: 00000000
tick_broadcast_oneshot_mask: 00000000

Tick Device: mode:     1
Per CPU device: 0
Clock Event Device: lapic
 max_delta_ns:   343638624950
 min_delta_ns:   2401
 mult:           26840324
 shift:          32
 mode:           3
 next_event:     15515578273147 nsecs
 set_next_event: lapic_next_event
 shutdown:       lapic_timer_shutdown
 periodic:       lapic_timer_set_periodic
 oneshot:        lapic_timer_set_oneshot
 oneshot stopped: lapic_timer_shutdown
 event_handler:  hrtimer_interrupt

 retries:        261
```

| function | file | comment |
|----------|------|---------|
|CpuUtilization|/proc/stat| file contain cpu in different states that enables the cpu calculation|
|jiffies | /proc/timer_list/ | find 'jiffies:' give you total jiffies or (total_uptime*HZ)|
| HZ | /boot/config-$(uname -r), /proc/version | find 'CONFIG_HZ=', 3rd element or sysconf(_SC_CLK_TCK) |
| running processes | /proc/stat | find 'procs_running' |
| idle and active jiffies | /proc/stat | cpu idle and active time, find cpu parameters |
| Active jiffies & uptime for pid | /proc/uptime, /proc/[pid]/stat | find total uptime of system(first element), find 14.utime, 15.stime , 22.starttime|
| Ram | /proc/[pid]/statm | resident is how much ram is used, we are searching for 2nd element|

