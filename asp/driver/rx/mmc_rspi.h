//device node type
//rspi_mmc node's api

//rspi_mmc_node's status
typedef struct mmc_rspi_dev_status_type{
  uint32_t rspi_id;
  uint32_t ins_id;
  uint8_t Stat;
  uint8_t tout_flg;
} mmc_rspi_dstat;
