#ifndef __DEFS_H__
#define __DEFS_H__

#define MONGO_ADDRESS "192.168.10.1:27017"
#define MONGO_DB_NAME "db"

#define ZEROMQ_ADDRESS "tcp://192.168.10.1:25555"

#define RFCLIENT_RFSERVER_CHANNEL "rfclient<->rfserver"
#define RFSERVER_RFPROXY_CHANNEL "rfserver<->rfproxy"

#define RFSERVER_ID "rfserver"
#define RFPROXY_ID "rfproxy"

#define DEFAULT_RFCLIENT_INTERFACE "eth0"

#define SYSLOGFACILITY LOG_LOCAL7

#define RFVS_PREFIX 0x72667673
#define IS_RFVS(dp_id) !((dp_id >> 32) ^ RFVS_PREFIX)

#define RF_ETH_PROTO 0x0A0A /* RF ethernet protocol */
#define ETHERTYPE_ARP 0x0806

#define VLAN_HEADER_LEN 4
#define ETH_HEADER_LEN 14
#define ETH_CRC_LEN 4
#define ETH_PAYLOAD_MAX 1500
#define ETH_TOTAL_MAX (ETH_HEADER_LEN + ETH_PAYLOAD_MAX + ETH_CRC_LEN)
#define RF_MAX_PACKET_SIZE (VLAN_HEADER_LEN + ETH_TOTAL_MAX)

// We must match_l2 in order for packets to go up
#define MATCH_L2 true

typedef enum route_mod_type {
	RMT_ADD,			/* Add flow to datapath */
	RMT_DELETE,			/* Remove flow from datapath */
	RMT_CONTROLLER,			/* Add flow to datapath, output to controller */
        RMT_ADD_GROUP,                  /* Add group to datapath */
        RMT_DELETE_GROUP,               /* Remove group from datapath */
	/* Future implementation */
	//RMT_MODIFY		/* Modify existing flow (Unimplemented) */
} RouteModType;

typedef enum port_config_type {
    PCT_MAP_REQUEST,    /* (deprecated) Request for a mapping packet. */
    PCT_RESET,          /* Reset the client port to inactive. */
    PCT_MAP_SUCCESS,    /* Mapping was successful; port can be brought up. */
    PCT_ROUTEMOD_ACK,
} PortModType;

#define PC_MAP 0
#define PC_RESET 1

#define PRIORITY_BAND 0xA
#define PRIORITY_LOWEST 0x0000
#define PRIORITY_LOW 0x4010
#define PRIORITY_HIGH 0x8020
#define PRIORITY_HIGHEST 0xC030

#define TPORT_BGP 0x00B3
#define OFPP_CONTROLLER 0xFFFFFFFD

#define IPPROTO_OSPF 0x59

#define CONTROLLER_GROUP 1

#endif /* __DEFS_H__ */
