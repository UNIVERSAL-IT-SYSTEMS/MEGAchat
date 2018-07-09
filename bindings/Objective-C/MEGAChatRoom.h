#import <Foundation/Foundation.h>

typedef NS_ENUM (NSInteger, MEGAChatRoomChangeType) {
    MEGAChatRoomChangeTypeStatus         = 0x01,
    MEGAChatRoomChangeTypeUnreadCount    = 0x02,
    MEGAChatRoomChangeTypeParticipants   = 0x04,
    MEGAChatRoomChangeTypeTitle          = 0x08,
    MEGAChatRoomChangeTypeUserTyping     = 0x10,
    MEGAChatRoomChangeTypeClosed         = 0x20,
    MEGAChatRoomChangeTypeOwnPriv        = 0x40,
    MEGAChatRoomChangeTypeUserStopTyping = 0x80
};

typedef NS_ENUM (NSInteger, MEGAChatRoomPrivilege) {
    MEGAChatRoomPrivilegeUnknown   = -2,
    MEGAChatRoomPrivilegeRm        = -1,
    MEGAChatRoomPrivilegeRo        = 0,
    MEGAChatRoomPrivilegeStandard  = 2,
    MEGAChatRoomPrivilegeModerator = 3
};

@interface MEGAChatRoom : NSObject

/**
 * @brief The MegaChatHandle of the chat.
 */
@property (readonly, nonatomic) uint64_t chatId;

/**
 * @brief Your privilege level in this chat
 */
@property (readonly, nonatomic) MEGAChatRoomPrivilege ownPrivilege;
@property (readonly, nonatomic) NSUInteger peerCount;
@property (readonly, nonatomic, getter=isGroup) BOOL group;
@property (readonly, nonatomic) NSString *title;
@property (readonly, nonatomic, getter=hasCustomTitle) BOOL customTitle;
@property (readonly, nonatomic) MEGAChatRoomChangeType changes;
@property (readonly, nonatomic) NSInteger unreadCount;
@property (readonly, nonatomic) uint64_t userTypingHandle;
@property (readonly, nonatomic, getter=isActive) BOOL active;
@property (readonly, nonatomic, getter=isArchived) BOOL archived;


- (instancetype)clone;

- (NSInteger)peerPrivilegeByHandle:(uint64_t)userHande;
- (NSString *)peerFirstnameByHandle:(uint64_t)userHande;
- (NSString *)peerLastnameByHandle:(uint64_t)userHande;
- (NSString *)peerFullnameByHandle:(uint64_t)userHande;
- (NSString *)peerEmailByHandle:(uint64_t)userHande;
- (uint64_t)peerHandleAtIndex:(NSUInteger)index;
- (MEGAChatRoomPrivilege)peerPrivilegeAtIndex:(NSUInteger)index;
- (NSString *)peerFirstnameAtIndex:(NSUInteger)index;
- (NSString *)peerLastnameAtIndex:(NSUInteger)index;
- (NSString *)peerFullnameAtIndex:(NSUInteger)index;
- (BOOL)hasChangedForType:(MEGAChatRoomChangeType)changeType;

+ (NSString *)stringForPrivilege:(MEGAChatRoomPrivilege)privilege;
+ (NSString *)stringForChangeType:(MEGAChatRoomChangeType)changeType;

@end
