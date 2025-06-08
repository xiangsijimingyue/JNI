#ifndef INTERFACE_H__
#define INTERFACE_H__

// 检查标准头文件是否存在
#include <stdint.h>
#include <stdio.h>

#if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 199901L
// C89/C90环境下手动定义
#if !defined(uint8_t)
typedef unsigned char uint8_t;
#endif
#if !defined(uint16_t)
typedef unsigned short uint16_t;
#endif
#if !defined(uint32_t)
typedef unsigned int uint32_t;
#endif
#if !defined(uint64_t)
typedef unsigned long  uint64_t;
#endif
#else
// C99及以上环境直接包含标准头文件
#include <stdint.h>
#include <stdio.h>
#endif
typedef enum {
    REQ_LOGIN = 1,                // 登录请求
    REQ_LOGOUT = 2,               // 退出登录
    REQ_SUB_GROUP = 3,            // 进组请求
    REQ_GET_TALK = 4,             // 抢麦请求
    REQ_LOST_TALK = 5,            // 放麦请求
    REQ_UNSUB_GROUP = 6,          // 退组请求
    REQ_MONITOR_GROUP = 7,        // 监听请求
    REQ_REMOVE_MONITOR_GROUP = 8, // 移除监听请求
    REQ_CREATE_GROUP = 9,
    REQ_UPDATE_GROUP = 10,
    REQ_DESTROY_GROUP = 11,
    REQ_CHANGE_GROUP_OWNER = 12,
    REQ_QUERY_GROUP_LIST = 13,
    REQ_QUERY_GROUP_PAGE = 14,
    REQ_QUERY_GROUP_INFO = 15,         // 查询群组信息
    REQ_ADD_GROUP_MEMBER = 16,         // 添加成员请求
    REQ_REMOVE_GROUP_MEMBER = 17,      // 移除成员请求
    REQ_JOIN_GROUP = 18,               // 加入群组请求
    REQ_LEAVE_GROUP = 19,              // 离开群组请求
    REQ_QUERY_GROUP_MEMBER_PAGE = 20,  // 查询列表请求
    REQ_UPDATE_IN_GROUP_NICKNAME = 21, // 修改在群昵称请求
    RESP_LOGIN = 24,                   // 登录响应
    RESP_SUBSCRIBE_GROUP = 25,         // 订阅群组响应
    RESP_MONITOR_GROUP = 26,           // 监听群
    RESP_REMOVE_MONITOR_GROUP = 27,    // 取消监听群
    RESP_GET_TALK_RIGHT = 28,          // 抢麦响应
    RESP_OVER_TALK_RIGHT = 29,         // 放麦响应
    RESP_UNSUBSCRIBE_GROUP = 30,       // 取消订阅群组响应
    RESP_HEART_BEAT = 31,              // 心跳
    RESP_LOGOUT = 32,                  // 退出登录响应
    RESP_CREATE_GROUP = 33,
    RESP_UPDATE_GROUP = 34,
    RESP_DESTROY_GROUP = 35,
    RESP_CHANGE_GROUP_OWNER = 36,
    RESP_QUERY_GROUP_LIST = 37,
    RESP_QUERY_GROUP_PAGE = 38,
    RESP_QUERY_GROUP_INFO = 39,          // 查询群组信息响应
    RESP_ADD_GROUP_MEMBER = 40,          // 添加成员响应
    RESP_REMOVE_GROUP_MEMBER = 41,       // 移除成员响应
    RESP_JOIN_GROUP = 42,                // 加入群组响应
    RESP_LEAVE_GROUP = 43,               // 离开群组响应
    RESP_QUERY_GROUP_MEMBER_PAGE = 44,   // 查询群成员列表响应
    RESP_UPDATE_IN_GROUP_NICKNAME = 45,  // 修改在群昵称
    NET_EVENT_CONNECTED = 47,            // 连接成功
    NET_EVENT_DISCONNECTED = 48,         // 连接断开
    NOTIFY_GROUP_INFO_CHANGE = 49,       // 群组信息变更通知
    NOTIFY_MIC_STATUS_EVENT = 50,        // 麦克风状态通知（获取/失去麦克风）
    NOTIFY_GROUP_MEMBER_CHANGE = 51,     // 群组成员变更通知
    NOTIFY_GROUP_OWNER_TRANSFERRED = 52, // 群主转让通知
    NOTIFY_ONLINE_STATUS = 53,           // 在线状态通知
    NOTIFY_SUB_GROUP = 54,               // 订阅群组通知
} event_type_t;

// 网络配置参数
typedef struct {
    const char *signalling_server_ip; // 信令服务器地址
    uint16_t signalling_port;         // 信令服务器端口
    const char *rtp_server_ip;        //
    uint16_t rtp_server_port;         //
    uint16_t rtp_local_port;          // 本地UDP绑定端口
    uint16_t signalling_local_port;   //
    uint32_t reconnect_interval;      // 重连间隔(ms)
    uint32_t heartbeat_interval;
    uint32_t heartbeat_timeout; // 心跳超时时间（毫秒）
} NetworkConfig;

// 用户配置参数
typedef struct {
    uint16_t request_timeout_sec;
} UserConfig;
// 网络事件回调
typedef void (*NetworkEventCallback)(event_type_t type, const void *data, size_t len);
// 信令事件回调
typedef void (*UserworkEventCallback)(event_type_t type, const void *data, size_t len);
// 通知事件回调
typedef void (*UserNotifyEventCallback)(event_type_t type, const void *data, size_t len);
typedef void (*RequestTimeoutCallback)(event_type_t type, const void *data, size_t len);

#define TOKEN_LEN_MAX 200
#define USERNAM_LEN_MAX 50
#define PW_LEN_MAX 50
#define DEVICE_ID_LEN_MAX 50
#define OS_LEN_MAX 50
#define OS_VERSION_LEN_MAX 50
#define BRAND_LEN_MAX 50
#define DEVICE_MODE_LEN_MAX 50
#define AVATAR_LEN_MAX 200
#define NAME_LEN_MAX 50
#define IP_LEN_MAX 46
#define MONITOR_GROUPS_COUNT_MAX 10
#define USER_NUM_MAX 100
#define GROUPMEMBER 10
typedef struct _user_info {
    char token[TOKEN_LEN_MAX];
    char username[USERNAM_LEN_MAX];
    char password[PW_LEN_MAX];
    char device_id[DEVICE_ID_LEN_MAX];   // 设备标识符
    char os_type[OS_LEN_MAX];            // 操作系统类型 android ios rtos等
    char os_version[OS_VERSION_LEN_MAX]; // 操作系统版本
    char brand[BRAND_LEN_MAX];           // 终端品牌
    char model[DEVICE_MODE_LEN_MAX];     // 终端型号
    uint32_t log_type;                   // 登录类型
} user_info;

typedef enum OnlineStatus {
    ONLINESTATUS_ONLINE = 0,
    ONLINESTATUS_OFFLINE = 1,
} onlineStatus_t;

/*登录响应*/
typedef struct login_resp {
    uint32_t code;
    uint32_t user_id;
    char nickname[USERNAM_LEN_MAX];
    char avatar[AVATAR_LEN_MAX];
    onlineStatus_t login_online_status;
    uint32_t seq;
} login_resp;

/* 订阅群组响应 */
typedef struct sub_group_resp {
    int32_t code;
    char rtc_server_ip[IP_LEN_MAX];
    uint32_t rtc_server_port;
    uint64_t group_id;
    uint32_t userid;
    uint32_t seq;
} subgroup_resp;

typedef enum group_type {
    GROUP_TYPE_NOMAL = 0, /* 普通群组 */
    GROUP_TYPE_TEMP = 1   /* 临时群组 */
} group_type_t;

typedef struct {
    uint64_t group_id;
    char name[NAME_LEN_MAX];
    char avatar[AVATAR_LEN_MAX];
    group_type_t type;
    uint32_t owner_id;
    int64_t create_timestamp;
} group_info_t;

// 查询群组信息响应
typedef struct QueryGroup_Resp {
    int32_t code;
    group_info_t group;
    uint32_t seq;
} querygroup_resp_t;

typedef enum micstatus_type {
    MIC_GET = 0, /* 已抢麦 */
    MIC_LOST = 1 /* 已放麦 */
} micstatus_type_t;

typedef struct User {
    uint32_t userId;             /* 用户ID */
    char nickname[NAME_LEN_MAX]; /* 用户昵称 */
    char avatar[AVATAR_LEN_MAX]; /* 用户头像 */
    onlineStatus_t onlineStatu;
} User_t;

typedef enum subscribestatus_type { SUBSCRIBE = 0, UNSUBSCRIBE = 1 } subscribestatus_type_t;

// 群成员信息
typedef struct GroupMember {
    uint32_t userId;                        // 成员用户id
    User_t user;                            // 成员用户信息
    subscribestatus_type_t subscribeStatus; // 群组订阅状态
    uint32_t role;                          // 角色 1: 群成员 2: 管理员 3: 群主
    uint64_t joinTime5;                     // 加入时间 单位：毫秒
    char inNickname[NAME_LEN_MAX];          // 在群昵称
} groupmember;

typedef enum group_member_change_type {
    GROUP_MEM_CHANGE_TYPE_MEMBER_ADD = 0,  // 被动添加，比如邀请加入
    GROUP_MEM_CHANGE_TYPE_EMBER_KICK = 1,  // 被踢出，比如被群主踢出
    GROUP_MEM_CHANGE_TYPE_MEMBER_JOIN = 2, // 主动加入
    GROUP_MEM_CHANGE_TYPE_MEMBER_LEAVE = 3 // 主动退群
} group_mem_change_type_t;

typedef struct get_talk_resp {
    uint32_t code;
    uint64_t group_id;
    uint32_t user_id;
    uint32_t seq;
} get_talk_resp;

typedef struct lost_talk_resp {
    uint32_t code;
    uint64_t group_id;
    uint32_t user_id;
    uint32_t seq;
} lose_talk_resp;

typedef struct FailUser {
    int32_t reason;  // 失败原因
    uint32_t userid; // 失败用户
} failed_user;
// 添加成员
typedef struct add_groupmem_resp {
    uint32_t code;
    int successusers_count;
    uint32_t successUsers[USER_NUM_MAX];
    int failUsers_count;
    failed_user failUsers[USER_NUM_MAX];
    uint32_t seq;
} addgroupmem_resp;
// 移除成员
typedef struct remove_groupmem_resp {
    uint32_t code; // 移除结果
    uint32_t seq;
} removegroupmem_resp;
// 加入群组
typedef struct join_group_resp {
    uint32_t code;
    uint32_t seq;
} joingroup_resp;
// 离开群组
typedef struct leave_group_resp {
    uint32_t code;
    uint32_t seq;
} leavegroup_resp;
// 分页查询群成员列表
typedef struct query_groupMember_Page_Resp {
    uint32_t code;
    uint32_t pagesize;
    uint32_t pagenum;
    uint32_t total;
    int member_count;
    groupmember member[GROUPMEMBER];
    uint32_t seq;
} querygrouppage_resp;

typedef struct micstatusevent_notify {
    uint32_t user_id;
    uint64_t group_id;
    micstatus_type_t micStatus; // 0:已订阅 1:未订阅
    uint32_t seq;
} micstatus_event_notify;

typedef struct groupinfo_change_notify {
    uint64_t group_id;
    char group_name[NAME_LEN_MAX];
    char group_avatar[AVATAR_LEN_MAX];
    uint32_t operator_id;
    group_type_t group_type;
    uint32_t seq;
} group_info_changed_notify;

typedef struct groupmember_change_notify {
    uint64_t group_id;
    group_mem_change_type_t group_mem_type;
    int changeUserIds_count;
    uint32_t changeUserIds[USER_NUM_MAX];
    uint32_t operatorId;
    uint32_t seq;
} group_mem_change_notify;

typedef struct groupowner_transferred_notify {
    uint64_t group_id;
    uint32_t prevOwner_id; // 前群主id
    uint32_t newOwner_id;  // 新群主id
    uint32_t operator_id;  // 操作者用户id
    uint32_t seq;
} group_owner_transferred_notify;

typedef struct unsub_group_resp {
    uint32_t code;
    uint32_t user_id;
    uint64_t group_id;
    uint32_t seq;
} unsubgroup_resp;

typedef struct logout_resp {
    uint32_t code;
    uint32_t seq;
} logout_resp;

typedef enum {
    ONLINE,
    DUPLICATE_USER,
    MOBILE_KICK,
    NET_ERROR,
    LOGING,
} online_status_t;

typedef struct online_status_notify {
    uint32_t user_id;
    online_status_t status;
} online_status_notify_t;

typedef struct sub_group_notify {
    uint32_t user_id;
    uint64_t group_id;
    int status; // 0:订阅  1：未订阅
    uint32_t seq;
} subgroup_notify;

typedef struct _group_resp_t {
    uint64_t groupId;
    char ip[IP_LEN_MAX];
    uint32_t port;
} group_resp_t;

typedef struct {
    int32_t code;
    uint32_t user_id;
    uint64_t success_group_id[MONITOR_GROUPS_COUNT_MAX];
    int success_groups_count;
    uint64_t fail_group_id[MONITOR_GROUPS_COUNT_MAX];
    int fail_groups_count;
    uint32_t seq;
} remove_monitor_group_resp;

typedef struct sub_monitor_group_resp {
    int32_t code;
    uint32_t user_id;
    group_resp_t success_group[MONITOR_GROUPS_COUNT_MAX];
    int success_groups_count;
    uint64_t fail_group_id[MONITOR_GROUPS_COUNT_MAX];
    int fail_groups_count;
    uint32_t seq;
} monitor_group_resp;

typedef struct _group_req {
    uint32_t user_id;
    uint32_t *user_list;
    int count;
    uint8_t *name;
    uint8_t *avatar;
} group_req_t;

typedef struct _update_group_req {
    uint32_t user_id;
    uint64_t group_id;
    uint8_t *name;
    uint8_t *avatar;
} update_group_req_t;

typedef struct _create_group_resp {
    int32_t code;
    group_info_t group;
    uint32_t seq;
} create_group_resp_t;

typedef struct _group_list_resp {
    int32_t code;
    int32_t group_count;
    group_info_t groups[10];
    uint32_t seq;
} group_list_resp_t;

typedef struct _group_page_resp {
    int32_t code;
    int32_t page_size;
    int32_t page_num;
    int32_t total;
    int32_t group_count;
    group_info_t groups[10];
    uint32_t seq;
} group_page_resp_t;

typedef struct _common_resp {
    uint32_t seq;
    int32_t code;
} common_resp_t;
// action timeout
typedef struct _timeout_resp {
    uint32_t seq;
} timeout_resp_t;

//  接口返回值
typedef struct _api_result {
    enum {
        RES_OK,   // 成功
        SEND_ERR, // 发送失败
        CONN_ERR, // 连接失败
        PB_ERR    // 编码失败
    } code;
    uint32_t seq;
} api_result_t;
typedef struct {
    int index;
    char name[256];
} audio_device_info_t;
// 网络初始化
int network_init(const NetworkConfig *config, NetworkEventCallback callback);
// 用户初始化
int user_manager_init(const UserConfig *config, UserworkEventCallback callback1, UserNotifyEventCallback callback2,
                      RequestTimeoutCallback timeout_cb);
// 登录接口
api_result_t sdk_login(user_info user);
// 订阅群组
api_result_t sdk_sub_group(uint64_t groupid);
// 抢麦接口
api_result_t sdk_get_talk(uint64_t groupid);
// 放麦接口
api_result_t sdk_lost_talk(uint64_t groupid);
// 取消订阅群组接口
api_result_t sdk_unsub_group(uint64_t groupid);
// 退出登录接口
api_result_t sdk_logout();
// 移除监听组
api_result_t sdk_remove_monitor_groups(uint64_t *group_list, int group_count);
// 添加监听组
api_result_t sdk_add_monitor_groups(uint64_t *group_list, int group_count);
// 添加群成员
api_result_t sdk_add_groupmem(uint32_t *userids, uint32_t num_userids);
// 移除群成员
api_result_t sdk_remove_groupmem(uint64_t groupid, uint32_t *userIds, uint32_t num_userids);
// 申请进群
api_result_t sdk_join_group(uint64_t groupid, char *invitecode);
// 退出群组
api_result_t sdk_leave_group(uint64_t groupid);
// 请求群组成员
api_result_t sdk_query_groupmem_page(uint64_t groupid, uint32_t pagesize, uint32_t pagenum);
// 查询群组信息
api_result_t sdk_query_group(uint64_t groupid);

/*群组操作接口*/
// 创建群组
api_result_t sdk_create_group(uint32_t *user_list, int32_t user_count, uint8_t *name, uint8_t *avatar);
// 更新群组信息
api_result_t sdk_update_group_info(uint64_t group_id, uint8_t *name, uint8_t *avatar);
// 转移群主
api_result_t sdk_change_group_owner(uint64_t group_id, uint32_t owner_id);
// 解散群组
api_result_t sdk_destroy_group(uint64_t group_id);
// 请求群组列表
api_result_t sdk_query_group_list();
// 按页请求群组列表
api_result_t sdk_query_group_page(int32_t page_num, int32_t page_size);
// 修改在群昵称
api_result_t sdk_update_in_group_nickname(uint64_t groupid, char *nickname);
void sdk_clean_up();

typedef struct {
    int sample_rate; // 采样率
    int channels;    // 通道数
    int bitdepth;
    int encode_type; // 编码器选择   0: amr 仅支持0 amr
} audio_config_t;
int audio_control_init(audio_config_t config);
void sdk_start(int cores); // cores:  1 单核运行   >1多核心运行
void sdk_clean_up();
int get_playback_list(audio_device_info_t *list);
int get_mic_list(audio_device_info_t *list);
int select_playback_device(int index);

int select_mic(int index);
#endif