; Define for CH373 & CH374          */
; Website:  http://winchiphead.com  */
; Email:    tech@winchiphead.com    */
; Author:   W.ch 2005.10            */
; V1.3 for CH373/CH374              */

; ********************************************************************************************************************* */
; USBЭ��㶨�� */

; USB�İ���ʶPID, ������ʽ�����õ� */
DEF_USB_PID_NULL	EQU     00H							;����PID, δ����
DEF_USB_PID_SOF		EQU     05H
DEF_USB_PID_SETUP	EQU     0DH
DEF_USB_PID_IN		EQU     09H
DEF_USB_PID_OUT		EQU     01H
DEF_USB_PID_ACK		EQU     02H
DEF_USB_PID_NAK		EQU     0AH
DEF_USB_PID_STALL	EQU     0EH
DEF_USB_PID_DATA0	EQU     03H
DEF_USB_PID_DATA1	EQU     0BH
DEF_USB_PID_PRE		EQU     0CH

; ********************************************************************************************************************* */
; оƬ���� */

; �Ĵ����������� */

RAM_ENDP0_SIZE		EQU     008H		; �˵�0�Ļ��������� */
RAM_ENDP0_TRAN		EQU     020H		; �˵�0���ͻ���������ʼ��ַ */
RAM_ENDP0_RECV		EQU     028H		; �˵�0���ջ���������ʼ��ַ */
RAM_ENDP1_SIZE		EQU     008H		; �˵�1�Ļ��������� */
RAM_ENDP1_TRAN		EQU     030H		; �˵�1���ͻ���������ʼ��ַ */
RAM_ENDP1_RECV		EQU     038H		; �˵�1���ջ���������ʼ��ַ */
RAM_ENDP2_SIZE		EQU     040H		; �˵�2�Ļ��������� */
RAM_ENDP2_TRAN		EQU     040H		; �˵�2���ͻ���������ʼ��ַ */
RAM_ENDP2_RECV		EQU     0C0H		; �˵�2���ջ���������ʼ��ַ */
RAM_ENDP2_EXCH		EQU     080H		; �˵�2���û���������ʼ��ַ */
RAM_HOST_TRAN		EQU     040H		; �������ͻ���������ʼ��ַ */
RAM_HOST_RECV		EQU     0C0H		; �������ջ���������ʼ��ַ */
RAM_HOST_EXCH		EQU     080H		; �������û���������ʼ��ַ */

REG_HUB_SETUP		EQU		002H		; ��USB������ʽ: ROOT-HUB���� */
REG_HUB_CTRL		EQU		003H		; ��USB������ʽ: ROOT-HUB���� */
REG_SYS_INFO		EQU     004H		; ϵͳ��Ϣ, ֻ�� */
REG_SYS_CTRL		EQU     005H		; ϵͳ����, ����������λӰ�� */
REG_USB_SETUP		EQU     006H		; USB���� */
REG_INTER_EN		EQU     007H		; �ж�ʹ�� */
REG_USB_ADDR		EQU     008H		; USB�豸��ַ */
REG_INTER_FLAG		EQU     009H		; �жϱ�־, ֻ��, λд1��0 */
REG_USB_STATUS		EQU     00AH		; USB״̬, ֻ�� */
REG_USB_LENGTH		EQU     00BH		; USB����, ��Ϊ��ǰUSB���ճ���, �豸��ʽ��дΪUSB�˵�2, ������ʽ��дΪUSB�������ͳ��� */
REG_USB_ENDP0		EQU     00CH		; ��USB�豸��ʽ: USB�˵�0���� */
REG_USB_ENDP1		EQU     00DH		; ��USB�豸��ʽ: USB�˵�1���� */
REG_USB_H_PID		EQU     00DH		; ��USB������ʽ: USB�������� */
REG_USB_ENDP2		EQU     00EH		; ��USB�豸��ʽ: USB�˵�2���� */
REG_USB_H_CTRL		EQU     00EH		; ��USB������ʽ: USB�������� */

; �Ĵ�����λ�����ú궨�� */

BIT_HUB0_EN			EQU     001H		; HUB0�˿ڵ�USB����ʹ��: 0-��ֹ, 1-���� */
BIT_HUB0_RESET		EQU     002H		; HUB0�˿ڵ�USB���߸�λ����: 0-����λ, 1-��λ */
BIT_HUB0_POLAR		EQU     004H		; HUB0�˿ڵ��źż��Կ���: 0-������/ȫ��, 1-������/���� */
BIT_HUB0_ATTACH		EQU     008H		; HUB0�˿ڵ�USB�豸����״̬(ֻ��): 0-��δ����/�Ͽ�/�γ�, 1-�Ѿ�����/���� */
BIT_HUB1_DX_IN		EQU     010H		; HUB1ȫ��������ʱUD+����/���ٸ�����ʱUD-���ŵĲ���״̬: 0-�͵�ƽ,�ٶ�ʧ��, 1-�ߵ�ƽ,�ٶ�ƥ�� */
BIT_HUB2_DX_IN		EQU     020H		; HUB2ȫ��������ʱUD+����/���ٸ�����ʱUD-���ŵĲ���״̬: 0-�͵�ƽ,�ٶ�ʧ��, 1-�ߵ�ƽ,�ٶ�ƥ�� */
BIT_HUB_PRE_PID		EQU     040H		; ����ǰ�ð�PRE PID�������: 0-��ֹ, 1-����(�ⲿ�豸��USB-HUB) */
BIT_HUB_DISABLE		EQU     080H		; ��ֹROOT-HUB������������: 0-����(��USB������ʽ), 1-��ֹ(Ĭ��) */

BIT_HUB1_EN			EQU     001H		; HUB1�˿ڵ�USB����ʹ��: 0-��ֹ, 1-���� */
BIT_HUB1_RESET		EQU     002H		; HUB1�˿ڵ�USB���߸�λ����: 0-����λ, 1-��λ */
BIT_HUB1_POLAR		EQU     004H		; HUB1�˿ڵ��źż��Կ���: 0-������/ȫ��, 1-������/���� */
BIT_HUB1_ATTACH		EQU     008H		; HUB1�˿ڵ�USB�豸����״̬(ֻ��): 0-��δ����/�Ͽ�/�γ�, 1-�Ѿ�����/���� */
BIT_HUB2_EN			EQU     010H		; HUB2�˿ڵ�USB����ʹ��: 0-��ֹ, 1-���� */
BIT_HUB2_RESET		EQU     020H		; HUB2�˿ڵ�USB���߸�λ����: 0-����λ, 1-��λ */
BIT_HUB2_POLAR		EQU     040H		; HUB2�˿ڵ��źż��Կ���: 0-������/ȫ��, 1-������/���� */
BIT_HUB2_ATTACH		EQU     080H		; HUB2�˿ڵ�USB�豸����״̬(ֻ��): 0-��δ����/�Ͽ�/�γ�, 1-�Ѿ�����/���� */

BIT_INFO_HW_ID		EQU     003H		; Ӳ��ʶ��λ: ���ǳ���01, ����˵����������Ӳ���������� */
BIT_INFO_USB_DM		EQU     004H		; USB����UD-���ŵ��߼���ƽ״̬: 0-�͵�ƽ, 1-�ߵ�ƽ */
BIT_INFO_USB_DP		EQU     008H		; USB����UD+���ŵ��߼���ƽ״̬: 0-�͵�ƽ, 1-�ߵ�ƽ */
BIT_INFO_CLK_8KHZ	EQU		010H		; Ӳ��8KHzʱ��λ */
BIT_INFO_SOF_PRES	EQU     020H		; Ӳ��1mS��ʱ����״̬,����USB����, 1˵����Ҫ����SOF */
BIT_INFO_WAKE_UP	EQU     040H		; оƬ����״̬: 0-����˯�߻��ѹ�����, 1-�ѻ��� */
BIT_INFO_POWER_RST	EQU     080H		; Ӳ���ϵ縴λ���״̬: 0-���ڸ�λ, 1-��λ��� */

BIT_CTRL_OSCIL_OFF	EQU     001H		; ʱ����������: 0-������, 1-ֹͣ�� */
BIT_CTRL_CLK_12MHZ	EQU		002H		; ����ʱ��Ƶ��ѡ��: 0-24MHz, 1-12MHz */
BIT_CTRL_USB_POWER	EQU     004H		; V3���ŵ�USB��Դ����������: 0-����, 1-���� */
BIT_CTRL_RESET_NOW	EQU     008H		; оƬ������λ����: 0-����λ, 1-��λ */
BIT_CTRL_WATCH_DOG	EQU     010H		; RST���ź�RST#���ŵĿ��Ź���λʹ��: 0-����, 1-���� */
BIT_CTRL_INT_PULSE	EQU     020H		; INT#���ŵ��ж������ʽ: 0-�͵�ƽ�ж�, 1-�͵�ƽ�����ж� */
BIT_CTRL_OE_POLAR	EQU     040H		; UEN���ŵ�USB���ʹ�ܼ���: 0-�ߵ�ƽʹ��, 1-�͵�ƽʹ�� */

BIT_SETP_TRANS_EN	EQU     001H		; ��USB�豸��ʽ: USB�豸����ʹ��: 0-��ֹ, 1-���� */
BIT_SETP_PULLUP_EN	EQU     002H		; ��USB�豸��ʽ: USB�����������: 0-������������, 1-������������ */
BIT_SETP_BUS_CTRL	EQU     003H		; ��USB������ʽ: USB����״̬����: 00-����/����, 01-D+��D-��(���߸�λ), 10-����, 11-D+��D-��(���߻ָ�) */
;#define	M_SET_USB_BUS_FREE( old )		( (old) & ~ BIT_SETP_BUS_CTRL | 0x00 )		; ��USB������ʽ: USB���߿��� */
;#define	M_SET_USB_BUS_RESET( old )		( (old) & ~ BIT_SETP_BUS_CTRL | 0x01 )		; ��USB������ʽ: USB����״̬����/D+��D-��(���߸�λ) */
;#define	M_SET_USB_BUS_RESUME( old )		( (old) & ~ BIT_SETP_BUS_CTRL | 0x03 )		; ��USB������ʽ: USB����״̬����/D+��D-��(���߻ָ�) */
BIT_SETP_RAM_MODE	EQU     00CH		; ���û�����Ӧ�÷�ʽ: 00-���ñ��û�����, 01-���ӽ��ջ���������������128�ֽ�, 10-���ڷ��͵ڶ�������, 11-���ڽ��յڶ������� */
;#define	M_SET_RAM_MODE_OFF( old )		( (old) & ~ BIT_SETP_RAM_MODE | 0x00 )		; ���û�������ʽ/���ñ��û����� */
;#define	M_SET_RAM_MODE_128( old )		( (old) & ~ BIT_SETP_RAM_MODE | 0x04 )		; ���û�������ʽ/���ӽ��ջ���������������128�ֽ� */
;#define	M_SET_RAM_MODE_2TX( old )		( (old) & ~ BIT_SETP_RAM_MODE | 0x08 )		; ���û�������ʽ/���ڷ��͵ĵڶ�������,֧���������� */
;#define	M_SET_RAM_MODE_2RX( old )		( (old) & ~ BIT_SETP_RAM_MODE | 0x0C )		; ���û�������ʽ/���ڽ��յĵڶ�������,֧���������� */
BIT_SETP_LOW_SPEED	EQU     020H		; USB���ߴ����ٶ�: 0-12Mbps, 1-1.5Mbps */
BIT_SETP_USB_SPEED	EQU     030H		; USB��������: 00-ȫ��ģʽ/������12Mbps, 11-����ģʽ/������1.5Mbps */
BIT_SETP_LED_ACT	EQU     040H		; ��USB�豸��ʽ: ACT#���ŵ͵�ƽ�ļ����¼�: 0-�շ��������, 1-USB����� */
BIT_SETP_AUTO_SOF	EQU     040H		; ��USB������ʽ: �Զ�����SOFʹ��: 0-��ֹ, 1-���� */
BIT_SETP_HOST_MODE	EQU     080H		; USB���ӷ�ʽѡ��: 0-�豸��ʽ, 1-������ʽ */

BIT_IE_TRANSFER		EQU     001H		; USB��������ж�ʹ��, 1��Ч */
BIT_IE_BUS_RESET	EQU     002H		; ��USB�豸��ʽ: USB���߸�λ�ж�ʹ��, 1��Ч */
BIT_IE_DEV_DETECT	EQU     002H		; ��USB������ʽ: USB�豸����ж�ʹ��, 1��Ч */
BIT_IE_USB_SUSPEND	EQU     004H		; USB���߹����ж�ʹ��, 1��Ч */
BIT_IE_USB_RESUME	EQU     008H		; USB���߻ָ�/�����ж�ʹ��, 1��Ч, 0-ʹ��оƬ��������ж�, 1-ʹ��USB���߻ָ��ж� */
BIT_IE_CLK_OUT_DIV	EQU     0F0H		; �ɱ��ʱ�ӵķ�Ƶ����: ���Ƶ��Ϊ48MHz/(��ֵ+1), ����: 0000-48MHz, 0001-24MHz, 0010-16MHz, 1111-3MHz */
;#define	M_SET_CLK_DIV( old, div )		( (old) & ~ BIT_IE_CLK_OUT_DIV | (div) << 4 )	; ����ʱ�������Ƶ���� */

BIT_ADDR_USB_DEV	EQU     07FH		; ���豸��ʽ��Ϊ������ΪUSB�豸�ĵ�ַ, ��������ʽ��Ϊ��ǰ��������USB�豸��ַ */

BIT_IF_INTER_FLAG	EQU     00FH		; ���е�USB�жϱ�־ */
BIT_IF_TRANSFER		EQU     001H		; USB��������жϱ�־, 1��Ч, ���λд1���־, ��λ��ÿ��USB������ɺ��Զ���1 */
BIT_IF_BUS_RESET	EQU     002H		; ��USB�豸��ʽ: USB���߸�λ�жϱ�־, 1��Ч, ���λд1���־, ��λ�ڼ�⵽USB���߸�λʱ�Զ���1 */
BIT_IF_DEV_DETECT	EQU     002H		; ��USB������ʽ: USB�豸��μ���жϱ�־, 1��Ч, ���λд1���־, ��λ�ڼ�⵽USB�豸��κ��Զ���1 */
BIT_IF_USB_SUSPEND	EQU     004H		; USB���߹����жϱ�־, 1��Ч, ���λд1���־, ��λ�ڼ�⵽USB���߹���ʱ�Զ���1 */
BIT_IF_WAKE_UP		EQU     008H		; оƬ��������жϱ�־, 1��Ч, ���λд1���־, ��λ��оƬ������ɺ��Զ���1 */
BIT_IF_USB_RESUME	EQU     008H		; USB���߻ָ�/�����жϱ�־, 1��Ч, ���λд1���־, ��λ�ڼ�⵽USB���߻ָ�ʱ�Զ���1 */
BIT_IF_USB_PAUSE	EQU     010H		; USB������ͣ��־, 1��Ч, ���λд1���־, ��λ��ÿ��USB������ɺ��Զ���1 */
BIT_IF_DEV_ATTACH	EQU     020H		; USB�豸����״̬: 0-��δ����/�Ͽ�/�γ�, 1-������һ��USB�豸�Ѿ�����/���� */
BIT_IF_USB_OE		EQU     040H		; UEN���ŵ�USB���ʹ��״̬: 0-UEN����Ϊ�͵�ƽ, 1-UEN����Ϊ�ߵ�ƽ */
BIT_IF_USB_DX_IN	EQU     080H		; HUB0ȫ��������ʱUD+����/���ٸ�����ʱUD-���ŵĲ���״̬: 0-�͵�ƽ,�ٶ�ʧ��, 1-�ߵ�ƽ,�ٶ�ƥ�� */
BIT_HUB0_DX_IN		EQU		080H		; HUB0ȫ��������ʱUD+����/���ٸ�����ʱUD-���ŵĲ���״̬: 0-�͵�ƽ,�ٶ�ʧ��, 1-�ߵ�ƽ,�ٶ�ƥ�� */

BIT_STAT_THIS_ENDP	EQU     003H		; ��USB�豸��ʽ: USB�����Ŀ�Ķ˵��: 00-�˵�0, 01-�˵�1, 10-�˵�2, 11-���� */
BIT_STAT_THIS_PID	EQU     00CH		; ��USB�豸��ʽ: USB���������/����PID: 00-OUT����, 01-����, 10-IN����, 11-SETUP���� */
BIT_STAT_PID_ENDP	EQU     00FH		; ��USB�豸��ʽ: USB���������Ͷ˵��,�ο������USB_INT_EP*���� */
BIT_STAT_DEV_RESP	EQU     00FH		; ��USB������ʽ: USB�豸��Ӧ��PID: XX00=�����ʱ,����ֵ-ͬPID����,�ο������USB_INT_RET_*���� */
;M_IS_HOST_TIMEOUT( status )		( ( (status) & 0x03 ) == 0 )		; ���USB����״̬�Ƿ�ΪӦ��ʱ/���� */
;M_IS_HOST_IN_DATA( status )		( ( (status) & BIT_STAT_DEV_RESP & ~ ( DEF_USB_PID_DATA0 ^ DEF_USB_PID_DATA1 ) ) == ( DEF_USB_PID_DATA0 & DEF_USB_PID_DATA1 ) )	; ����Ƿ񷵻�DATA0����DATA1 */
BIT_STAT_TOG_MATCH	EQU     010H		; ָʾ��ǰ�Ĵ����Ƿ�ɹ�/��ǰ���յ����ݰ��Ƿ�ͬ��: 0-��ͬ��, 1-ͬ�� */
BIT_STAT_BUS_RESET	EQU     020H		; ��ǰUSB���߸�λ״̬: 0-û�и�λ, 1-���ڸ�λ */
BIT_STAT_SUSPEND	EQU     040H		; ��ǰUSB���߹���״̬: 0-�����л, 1-���߹��� */
BIT_STAT_SIE_FREE	EQU     080H		; ��ǰUSB�ӿ�����SIE��״̬: 0=æ/���ڴ���, 1=����/�ȴ� */

BIT_EP0_TRAN_RESP	EQU     00FH		; ��USB�豸��ʽ: �˵�0������Ӧ: 0000~1000-Ӧ�����ݳ���0~8, 1110-Ӧ��NAK, 1111-Ӧ��STALL,����ֵ-���� */
;#define	M_SET_EP0_TRAN_ACK( old, len )	( (old) & ~ BIT_EP0_TRAN_RESP | (len) & 0x0F )	; ��USB�豸��ʽ: �˵�0������Ӧ/Ӧ��ACK */
;#define	M_SET_EP0_TRAN_NAK( old )		( (old) & ~ BIT_EP0_TRAN_RESP | 0x0E )		; ��USB�豸��ʽ: �˵�0������Ӧ/Ӧ��NAK */
;#define	M_SET_EP0_TRAN_STA( old )		( (old) & ~ BIT_EP0_TRAN_RESP | 0x0F )		; ��USB�豸��ʽ: �˵�0������Ӧ/Ӧ��STALL */
BIT_EP0_RECV_RESP	EQU     030H		; ��USB�豸��ʽ: �˵�0������Ӧ: 00-Ӧ��ACK, 01-����, 10-Ӧ��NAK, 11-Ӧ��STALL */
;#define	M_SET_EP0_RECV_ACK( old )		( (old) & ~ BIT_EP0_RECV_RESP | 0x00 )		; ��USB�豸��ʽ: �˵�0������Ӧ/Ӧ��ACK */
;#define	M_SET_EP0_RECV_NAK( old )		( (old) & ~ BIT_EP0_RECV_RESP | 0x20 )		; ��USB�豸��ʽ: �˵�0������Ӧ/Ӧ��NAK */
;#define	M_SET_EP0_RECV_STA( old )		( (old) & ~ BIT_EP0_RECV_RESP | 0x30 )		; ��USB�豸��ʽ: �˵�0������Ӧ/Ӧ��STALL */
BIT_EP0_TRAN_TOG	EQU     040H		; ��USB�豸��ʽ: �˵�0����ͬ����־: 0-DATA0, 1-DATA1 */
BIT_EP0_RECV_TOG	EQU     080H		; ��USB�豸��ʽ: �˵�0����ͬ����־: 0-DATA0, 1-DATA1 */

BIT_EP1_TRAN_RESP	EQU     00FH		; ��USB�豸��ʽ: �˵�1������Ӧ: 0000~1000-Ӧ�����ݳ���0~8, 1110-Ӧ��NAK, 1111-Ӧ��STALL,����ֵ-���� */
;#define	M_SET_EP1_TRAN_ACK( old, len )	( (old) & ~ BIT_EP1_TRAN_RESP | (len) & 0x0F )	; ��USB�豸��ʽ: �˵�1������Ӧ/Ӧ��ACK */
;#define	M_SET_EP1_TRAN_NAK( old )		( (old) & ~ BIT_EP1_TRAN_RESP | 0x0E )		; ��USB�豸��ʽ: �˵�1������Ӧ/Ӧ��NAK */
;#define	M_SET_EP1_TRAN_STA( old )		( (old) & ~ BIT_EP1_TRAN_RESP | 0x0F )		; ��USB�豸��ʽ: �˵�1������Ӧ/Ӧ��STALL */
BIT_EP1_RECV_RESP	EQU     030H		; ��USB�豸��ʽ: �˵�1������Ӧ: 00-Ӧ��ACK, 01-����, 10-Ӧ��NAK, 11-Ӧ��STALL */
;#define	M_SET_EP1_RECV_ACK( old )		( (old) & ~ BIT_EP1_RECV_RESP | 0x00 )		; ��USB�豸��ʽ: �˵�1������Ӧ/Ӧ��ACK */
;#define	M_SET_EP1_RECV_NAK( old )		( (old) & ~ BIT_EP1_RECV_RESP | 0x20 )		; ��USB�豸��ʽ: �˵�1������Ӧ/Ӧ��NAK */
;#define	M_SET_EP1_RECV_STA( old )		( (old) & ~ BIT_EP1_RECV_RESP | 0x30 )		; ��USB�豸��ʽ: �˵�1������Ӧ/Ӧ��STALL */
BIT_EP1_TRAN_TOG	EQU     040H		; ��USB�豸��ʽ: �˵�1����ͬ����־: 0-DATA0, 1-DATA1 */
BIT_EP1_RECV_TOG	EQU     080H		; ��USB�豸��ʽ: �˵�1����ͬ����־: 0-DATA0, 1-DATA1 */

BIT_HOST_PID_ENDP	EQU     00FH		; ��USB������ʽ: Ŀ�Ķ˵��: 0000~1111-�˵��0~15 */
BIT_HOST_PID_TOKEN	EQU     0F0H		; ��USB������ʽ: ָ������/����PID: 1101-SETUP����, 0001-OUT����, 1001-IN����, 0101-SOF��,����ֵ-���� */
;M_MK_HOST_PID_ENDP( pid, endp )	( (pid) << 4 | (endp) & BIT_HOST_PID_ENDP )		; ������/����PID��Ŀ�Ķ˵������USB������������ */

BIT_EP2_TRAN_RESP	EQU     003H		; ��USB�豸��ʽ: �˵�2������Ӧ: 00-Ӧ������, 01-ͬ��/��ʱ����, 10-Ӧ��NAK, 11-Ӧ��STALL */
;#define	M_SET_EP2_TRAN_ACK( old )		( (old) & ~ BIT_EP2_TRAN_RESP | 0x00 )		; ��USB�豸��ʽ: �˵�2������Ӧ/Ӧ��ACK */
;#define	M_SET_EP2_TRAN_ISO( old )		( (old) & ~ BIT_EP2_TRAN_RESP | 0x01 )		; ��USB�豸��ʽ: �˵�2������Ӧ/ͬ��/��ʱ����/����Ӧ�� */
;#define	M_SET_EP2_TRAN_NAK( old )		( (old) & ~ BIT_EP2_TRAN_RESP | 0x02 )		; ��USB�豸��ʽ: �˵�2������Ӧ/Ӧ��NAK */
;#define	M_SET_EP2_TRAN_STA( old )		( (old) & ~ BIT_EP2_TRAN_RESP | 0x03 )		; ��USB�豸��ʽ: �˵�2������Ӧ/Ӧ��STALL */
BIT_EP2_RECV_RESP	EQU     030H		; ��USB�豸��ʽ: �˵�2������Ӧ: 00-Ӧ��ACK, 01-ͬ��/��ʱ����, 10-Ӧ��NAK, 11-Ӧ��STALL */
;#define	M_SET_EP2_RECV_ACK( old )		( (old) & ~ BIT_EP2_RECV_RESP | 0x00 )		; ��USB�豸��ʽ: �˵�2������Ӧ/Ӧ��ACK */
;#define	M_SET_EP2_RECV_ISO( old )		( (old) & ~ BIT_EP2_RECV_RESP | 0x10 )		; ��USB�豸��ʽ: �˵�2������Ӧ/ͬ��/��ʱ����/����Ӧ�� */
;#define	M_SET_EP2_RECV_NAK( old )		( (old) & ~ BIT_EP2_RECV_RESP | 0x20 )		; ��USB�豸��ʽ: �˵�2������Ӧ/Ӧ��NAK */
;#define	M_SET_EP2_RECV_STA( old )		( (old) & ~ BIT_EP2_RECV_RESP | 0x30 )		; ��USB�豸��ʽ: �˵�2������Ӧ/Ӧ��STALL */
BIT_EP2_TRAN_TOG	EQU     040H		; ��USB�豸��ʽ: �˵�2����ͬ����־: 0-DATA0, 1-DATA1 */
BIT_EP2_RECV_TOG	EQU     080H		; ��USB�豸��ʽ: �˵�2����ͬ����־: 0-DATA0, 1-DATA1 */

BIT_HOST_TRAN_ISO	EQU     001H		; ��USB������ʽ: �������͵Ĵ�������: 0-����/����/�жϴ���, 1-ͬ��/��ʱ���� */
BIT_HOST_START		EQU     008H		; ��USB������ʽ: ����������������: 0-��ͣ, 1-��������,��ɺ��Զ���0 */
BIT_HOST_RECV_ISO	EQU     010H		; ��USB������ʽ: �������յĴ�������: 0-����/����/�жϴ���, 1-ͬ��/��ʱ���� */
BIT_HOST_TRAN_TOG	EQU     040H		; ��USB������ʽ: ��������ͬ����־: 0-DATA0, 1-DATA1 */
BIT_HOST_RECV_TOG	EQU     080H		; ��USB������ʽ: ��������ͬ����־: 0-DATA0, 1-DATA1 */

; ״̬������ȳ��� */

CMD_SPI_374READ		EQU     0C0H		; SPI���������� */
CMD_SPI_374WRITE	EQU     080H		; SPIд�������� */

; ********************************************************************************************************************* */
; USB״̬ */

; ����״̬��������USB�豸��ʽ */
;   λ4ָʾ��ǰ���յ����ݰ��Ƿ�ͬ��, 0=��ͬ��, 1-ͬ�� */
;   λ3-λ2ָʾ��ǰ����, 00=OUT, 10=IN, 11=SETUP */
;   λ1-λ0ָʾ��ǰ�˵�, 00=�˵�0, 01=�˵�1, 10=�˵�2 */
USB_INT_EP0_SETUP	EQU     0CH							;USB�˵�0��SETUP
USB_INT_EP0_OUT		EQU     00H							;USB�˵�0��OUT
USB_INT_EP0_IN		EQU     08H							;USB�˵�0��IN
USB_INT_EP1_OUT		EQU     01H							;USB�˵�1��OUT
USB_INT_EP1_IN		EQU     09H							;USB�˵�1��IN
USB_INT_EP2_OUT		EQU     02H							;USB�˵�2��OUT
USB_INT_EP2_IN		EQU     0AH							;USB�˵�2��IN

; ����״̬��������USB������ʽ */
;   λ4ָʾ��ǰ���յ����ݰ��Ƿ�ͬ��, 0=��ͬ��, 1-ͬ�� */
;   λ3-λ0ָʾUSB�豸��Ӧ��: 0010=ACK, 1010=NAK, 1110=STALL, 0011=DATA0, 1011=DATA1, XX00=Ӧ�������߳�ʱ��Ӧ�� */
USB_INT_RET_ACK		EQU     DEF_USB_PID_ACK		; ����:����OUT/SETUP���񷵻�ACK */
USB_INT_RET_NAK		EQU     DEF_USB_PID_NAK		; ����:����NAK */
USB_INT_RET_STALL	EQU     DEF_USB_PID_STALL	; ����:����STALL */
USB_INT_RET_DATA0	EQU     DEF_USB_PID_DATA0	; ����:����IN���񷵻�DATA0 */
USB_INT_RET_DATA1	EQU     DEF_USB_PID_DATA1	; ����:����IN���񷵻�DATA1 */
USB_INT_RET_TOUT	EQU     000H		; ����:Ӧ�������߳�ʱ��Ӧ�� */
USB_INT_RET_TOUT1	EQU     004H		; ����:Ӧ�������߳�ʱ��Ӧ�� */
USB_INT_RET_TOUT2	EQU     008H		; ����:Ӧ�������߳�ʱ��Ӧ�� */
USB_INT_RET_TOUT3	EQU     00CH		; ����:Ӧ�������߳�ʱ��Ӧ�� */


; ����״̬����1XH����USB������ʽ�Ĳ���״̬����, �������ж�������ֵ, ����Ķ����Ϊ�˼���CH375 */
USB_INT_SUCCESS		EQU     14H							;USB������ߴ�������ɹ�
USB_INT_CONNECT		EQU     15H							;��⵽USB�豸�����¼�
USB_INT_DISCONNECT	EQU     16H							;��⵽USB�豸�Ͽ��¼�
USB_INT_BUF_OVER	EQU     17H							;USB���ƴ��������̫��, ���������
USB_INT_DISK_READ	EQU     1DH							;USB�洢�������ݿ�, �������ݶ���
USB_INT_DISK_WRITE	EQU     1EH							;USB�洢��д���ݿ�, ��������д��
USB_INT_DISK_ERR	EQU     1FH							;USB�洢������ʧ��

; ********************************************************************************************************************* */
; ����USB�ṹ����س��� */

; USB�������� */
DEF_USB_REQ_READ	EQU     80H							;���ƶ�����
DEF_USB_REQ_WRITE	EQU     00H							;����д����
DEF_USB_REQ_TYPE	EQU     60H							;������������
DEF_USB_REQ_STAND	EQU     00H							;��׼����
DEF_USB_REQ_CLASS	EQU     20H							;�豸������
DEF_USB_REQ_VENDOR	EQU     40H							;��������
DEF_USB_REQ_RESERVE	EQU     60H							;��������

; USB��׼�豸����, RequestType��λ6λ5=00(Standard) */
DEF_USB_CLR_FEATURE	EQU    01H
DEF_USB_SET_FEATURE	EQU    03H
DEF_USB_GET_STATUS	EQU    00H
DEF_USB_SET_ADDRESS	EQU    05H
DEF_USB_GET_DESCR	EQU    06H
DEF_USB_SET_DESCR	EQU    07H
DEF_USB_GET_CONFIG	EQU    08H
DEF_USB_SET_CONFIG	EQU    09H
DEF_USB_GET_INTERF	EQU    0AH
DEF_USB_SET_INTERF	EQU    0BH
DEF_USB_SYNC_FRAME	EQU    0CH

; ���������� */
USB_DEVICE_DESCR_TYPE		EQU     001H
USB_CONFIG_DESCR_TYPE		EQU     002H
USB_STRING_DESCR_TYPE		EQU     003H
USB_INTERF_DESCR_TYPE		EQU     004H
USB_ENDP_DESCR_TYPE			EQU     005H
USB_POWER_DESCR_TYPE		EQU     006H
USB_HID_DESCR_TYPE			EQU     021H
USB_REPORT_DESCR_TYPE		EQU     022H
USB_PHYSIC_DESCR_TYPE		EQU     023H

; �˵����ͺ����� */
USB_ENDP_DIR_MASK			EQU     080H
USB_ENDP_TYPE_MASK			EQU     003H
USB_ENDP_TYPE_CTRL			EQU     000H
USB_ENDP_TYPE_ISOCH			EQU     001H
USB_ENDP_TYPE_BULK			EQU     002H
USB_ENDP_TYPE_INTER			EQU     003H

; �豸��� */
USB_DEV_CLASS_RESERVED		EQU     000H
USB_DEV_CLASS_AUDIO			EQU     001H
USB_DEV_CLASS_COMMUNIC		EQU     002H
USB_DEV_CLASS_HUMAN_IF		EQU     003H
USB_DEV_CLASS_MONITOR		EQU     004H
USB_DEV_CLASS_PHYSIC_IF		EQU     005H
USB_DEV_CLASS_POWER			EQU     006H
USB_DEV_CLASS_PRINTER		EQU     007H
USB_DEV_CLASS_STORAGE		EQU     008H
USB_DEV_CLASS_HUB			EQU     009H
USB_DEV_CLASS_VEN_SPEC		EQU     0FFH

DEFAULT_ENDP0_SIZE			EQU		08H				; Ĭ�ϵĶ˵�0�������� */