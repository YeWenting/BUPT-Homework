//
//  datalink.h
//  SR_Protocol
//
//  Created by YeWenting. on 16/5/8.
//  Copyright © 2016年 School of Computer Science. All rights reserved.
//

#ifndef datalink_h
#define datalink_h

#include <stdio.h>
#define MAX_ACK_WAIT    1070                        //ack 帧最长等待时间
#define MAX_DATA_WAIT   250                         //piggybacking 最长等待时间
#define MAX_FRAME_SIZE  261

#define MAX_SEQ 7                                   //帧的序号空间，应当是2^n-1
#define NR_BUFS 4                                   //窗口大小，NR_BUFS = (MAX_SEQ + 1) / 2
#define inc(k) if(k < MAX_SEQ) k++; else k = 0      //计算k+1

struct FRAME {
    unsigned char control;                          //包含了 type, ack, seq 三个字段
    unsigned char data[PKT_LEN];
    unsigned int crc;
};

static unsigned char next_frame_to_send = 0;
static unsigned char frame_expected = 0;
static unsigned char ack_expected = 0;
static unsigned char too_far = NR_BUFS;
static unsigned char out_buffer[NR_BUFS][PKT_LEN], in_buffer[NR_BUFS][PKT_LEN], nbuffered;
static bool phl_ready = 0; //物理层是否ready?????????????
bool arrived[NR_BUFS]; //接收方输入缓存的bit map static???
bool no_nak = true; //是否发送了NAK，true则不再重复发送

#endif /* datalink_h */
