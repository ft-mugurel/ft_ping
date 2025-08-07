#ifndef FT_PING_H
# define FT_PING_H

# include <stdio.h>
# include <stdlib.h>
# include <netinet/ip_icmp.h>
# include <netinet/ip.h>
# include <sys/time.h>
# include <stdbool.h>
# include <stdint.h>

typedef struct s_ping
{
    // Genel ayarlar
    const char     *target;         // Kullanıcının verdiği hostname veya IP
    struct sockaddr_in addr;        // Hedef IP adresi (binary olarak)
    int             sockfd;         // Raw socket descriptor
    int             pid;            // ICMP header'da kullanılacak process ID

    // Flag'lerle ilgili ayarlar
    bool            flood;          // -f : flood mode aktif mi?
    bool            numeric;        // -n : DNS çözümleme yapma
    bool            verbose;        // -v : verbose mode aktif mi?
    bool            routing;        // -r : routing table bypass
    bool            timestamp_ip;   // --ip-timestamp aktif mi?
    bool            help;           // -h veya --help gösterimi

    int             preload;        // -l : başta kaç ping hızlı atılacak
    int             ttl;            // --ttl veya -t : time to live
    int             interval;       // -i : ping arası bekleme süresi (ms cinsinden)
    int             deadline;       // -w : toplam süre (sn)
    int             timeout;        // -W : her ping için timeout süresi (sn)
    int             count;          // -c : kaç ping gönderilecek
    int             payload_size;   // -s : ICMP packet data boyutu
    uint8_t         pattern;        // -p : ICMP payload içeriği için pattern

    // İstatistikler
    int             sent;           // Kaç ping gönderildi
    int             received;       // Kaç ping cevabı alındı
    int             errors;         // Alınan ICMP error mesajı sayısı
    struct timeval  start_time;     // Programın başlama zamanı
    double          rtt_min;        // En düşük RTT
    double          rtt_max;        // En yüksek RTT
    double          rtt_sum;        // RTT toplamı (ortalama için)
    double          rtt_sum2;       // RTT kare toplamı (stddev için)
}   t_ping;

// Fonksiyon prototipleri

t_ping parse(int argc, char *argv[]);

#endif
