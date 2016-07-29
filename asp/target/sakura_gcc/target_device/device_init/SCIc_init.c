void
sakura_port_config( void )
{
	/*
	 *  ポートの設定
	 */

	scic_uart_init( TARGET_PUTC_PORTID, UART_BAUDRATE, UART_CLKSRC );


	/* ポートP50をTxD2, ポートP52をRxD2に */
	/* MPC setting */
	/* unlock PFS write protection */
	sil_wrb_mem((void *)(MPC_PWPR_ADDR), MPC_PWPR_PFSW_CLEAR);
	sil_wrb_mem((void *)(MPC_PWPR_ADDR), MPC_PWPR_PFSWE_BIT);
	/* p50 is set as TxD2 mode */
	sil_wrb_mem((void *)(MPC_P50PFS_ADDR), MPC_PFS_PSELA);
	/* p52 is set as RxD2 mode*/
	sil_wrb_mem((void *)(MPC_P52PFS_ADDR), MPC_PFS_PSELA);
	/* lock PFS write */
	sil_wrb_mem((void *)(MPC_PWPR_ADDR), MPC_PWPR_PFSW_CLEAR);
	sil_wrb_mem((void *)(MPC_PWPR_ADDR), MPC_PWPR_B0WI_BIT);

	/* port mode setting */
	/* Port Mode Register(PMR) config. P50 and P52(RxD2) are setted to IP use */
	sil_wrb_mem((void *)(PORT5_PMR_ADDR) , 
					sil_reb_mem((void *)(PORT2_PMR_ADDR)) | PORT_PMR_B0_BIT | PORT_PMR_B2_BIT);
}
