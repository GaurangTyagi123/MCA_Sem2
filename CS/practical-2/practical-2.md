**Name : Gaurang Tyagi**

**Roll No : 16**

# Practical 2 : Email Header Analysis 

## Task 1 : Finding the Full Email Header

- Before analysis can begin, locate the full email header in your email client (Gmail/Outlook). The
method differs depending on the platform.
**header**
```
Received: from SA3PR19MB7370.namprd19.prod.outlook.com (::1) by
 MN0PR19MB6312.namprd19.prod.outlook.com with HTTPS; Tue, 19 Sep 2023 18:36:46
 +0000
Received: from BN0PR03CA0023.namprd03.prod.outlook.com (2603:10b6:408:e6::28)
 by SA3PR19MB7370.namprd19.prod.outlook.com (2603:10b6:806:317::17) with
 Microsoft SMTP Server (version=TLS1_2,
 cipher=TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384) id 15.20.6792.27; Tue, 19 Sep
 2023 18:36:45 +0000
Received: from BN8NAM11FT066.eop-nam11.prod.protection.outlook.com
 (2603:10b6:408:e6:cafe::23) by BN0PR03CA0023.outlook.office365.com
 (2603:10b6:408:e6::28) with Microsoft SMTP Server (version=TLS1_2,
 cipher=TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384) id 15.20.6792.28 via Frontend
 Transport; Tue, 19 Sep 2023 18:36:45 +0000
Authentication-Results: spf=temperror (sender IP is 137.184.34.4)
 smtp.mailfrom=ubuntu-s-1vcpu-1gb-35gb-intel-sfo3-06; dkim=none (message not
 signed) header.d=none;dmarc=temperror action=none
 header.from=atendimento.com.br;compauth=fail reason=001
Received-SPF: TempError (protection.outlook.com: error in processing during
 lookup of ubuntu-s-1vcpu-1gb-35gb-intel-sfo3-06: DNS Timeout)
Received: from ubuntu-s-1vcpu-1gb-35gb-intel-sfo3-06 (137.184.34.4) by
 BN8NAM11FT066.mail.protection.outlook.com (10.13.177.138) with Microsoft SMTP
 Server (version=TLS1_2, cipher=TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384) id
 15.20.6813.19 via Frontend Transport; Tue, 19 Sep 2023 18:36:44 +0000
X-IncomingTopHeaderMarker:
 OriginalChecksum:3B61F64750F88C5569DF38A496B2374685F23D8BC662A6A19B6823B2F6745D54;UpperCasedChecksum:62071BC7A7CF5B0844A7B406B0E9EFCDAA2CB94988E687CF8C56555AD4B52D30;SizeAsReceived:544;Count:9
Received: by ubuntu-s-1vcpu-1gb-35gb-intel-sfo3-06 (Postfix, from userid 0)
	id 39DEA3F725; Tue, 19 Sep 2023 18:35:49 +0000 (UTC)
Content-type: text/html; charset=UTF-8
Content-Transfer-Encoding: base64
Subject: CLIENTE PRIME - BRADESCO LIVELO: Seu cartão tem 92.990 pontos LIVELO expirando hoje!
From: BANCO DO BRADESCO LIVELO<banco.bradesco@atendimento.com.br>
To: phishing@pot
Message-Id: <20230919183549.39DEA3F725@ubuntu-s-1vcpu-1gb-35gb-intel-sfo3-06>
Date: Tue, 19 Sep 2023 18:35:49 +0000 (UTC)
X-IncomingHeaderCount: 9
Return-Path: root@ubuntu-s-1vcpu-1gb-35gb-intel-sfo3-06
X-MS-Exchange-Organization-ExpirationStartTime: 19 Sep 2023 18:36:44.2236
 (UTC)
X-MS-Exchange-Organization-ExpirationStartTimeReason: OriginalSubmit
X-MS-Exchange-Organization-ExpirationInterval: 1:00:00:00.0000000
X-MS-Exchange-Organization-ExpirationIntervalReason: OriginalSubmit
X-MS-Exchange-Organization-Network-Message-Id:
 b9106deb-bd54-4815-e5c9-08dbb93f5fab
X-EOPAttributedMessage: 0
X-EOPTenantAttributedMessage: 84df9e7f-e9f6-40af-b435-aaaaaaaaaaaa:0
X-MS-Exchange-Organization-MessageDirectionality: Incoming
X-MS-PublicTrafficType: Email
X-MS-TrafficTypeDiagnostic:
 BN8NAM11FT066:EE_|SA3PR19MB7370:EE_|MN0PR19MB6312:EE_
X-MS-Exchange-Organization-AuthSource:
 BN8NAM11FT066.eop-nam11.prod.protection.outlook.com
X-MS-Exchange-Organization-AuthAs: Anonymous
X-MS-UserLastLogonTime: 9/19/2023 6:25:15 PM
X-MS-Office365-Filtering-Correlation-Id: b9106deb-bd54-4815-e5c9-08dbb93f5fab
X-MS-Exchange-EOPDirect: true
X-Sender-IP: 137.184.34.4
X-SID-PRA: BANCO.BRADESCO@ATENDIMENTO.COM.BR
X-SID-Result: NONE
X-MS-Exchange-Organization-PCL: 2
X-MS-Exchange-Organization-SCL: 5
X-Microsoft-Antispam: BCL:9;
X-MS-Exchange-CrossTenant-OriginalArrivalTime: 19 Sep 2023 18:36:44.1298
 (UTC)
X-MS-Exchange-CrossTenant-Network-Message-Id: b9106deb-bd54-4815-e5c9-08dbb93f5fab
X-MS-Exchange-CrossTenant-Id: 84df9e7f-e9f6-40af-b435-aaaaaaaaaaaa
X-MS-Exchange-CrossTenant-AuthSource:
 BN8NAM11FT066.eop-nam11.prod.protection.outlook.com
X-MS-Exchange-CrossTenant-AuthAs: Anonymous
X-MS-Exchange-CrossTenant-FromEntityHeader: Internet
X-MS-Exchange-CrossTenant-RMS-PersistedConsumerOrg:
 00000000-0000-0000-0000-000000000000
X-MS-Exchange-Transport-CrossTenantHeadersStamped: SA3PR19MB7370
X-MS-Exchange-Transport-EndToEndLatency: 00:00:02.6179349
X-MS-Exchange-Processed-By-BccFoldering: 15.20.6792.025
X-Microsoft-Antispam-Mailbox-Delivery:
	wl:1;pcwl:1;ucf:0;jmr:0;ex:0;psp:0;auth:0;dest:I;OFR:TrustedSenderList;ENG:(5062000305)(920221119095)(90000117)(920221120095)(91040095)(9050020)(9075021)(9100341)(944500132)(2008001134)(4810010)(4910033)(9610028)(9560006)(10180021)(9439006)(9310011)(9220031)(120001);
X-Message-Info:
	qZelhIiYnPlgo3oeAkqKQrb/Je8fpvpPmRGjYwLej8PYXc5p/l16IG5I8gDUPoij+JWSvja0BAMLtkgrOcbx5zEN7V98T2UZUZs4k8BX/DcDfI7QJ0t2aouiqx4ENvkR1M3sDKP/XN09+50x9Rxi6onUtDV4eqq36VUi2qAa0zCzkJwjdl3Y9DzNE1OkaWjrHAizeUyMZ/UtK/Pz9zhA2A==
X-Message-Delivery: Vj0xLjE7dXM9MDtsPTA7YT0wO0Q9MTtHRD0yO1NDTD0tMQ==
X-Microsoft-Antispam-Message-Info:
	=?utf-8?B?QTlXRFVaTVRhbmFzVTRkbVBTSFRSUURrQTRyaDhzZVczY2RROWF3bVVDTWdk?=
 =?utf-8?B?bVU0VHJ2UU9wWUFLbXlFRWVUcmx1Z244ajk4M0JMRVYzZW9WVkE3NVZpK0dp?=
 =?utf-8?B?STVZSUFyRzdvQWNJeXEyNlNrZnBxcG9rZk5zQTAvMzBPbExJWWg2SFhEQWVv?=
 =?utf-8?B?RE1CeEhuMzB6Z0hkUWdoNDRWN0U0Y1JHcjlxOGRMUTRVOFBHR1RRTFlnNTBT?=
 =?utf-8?B?Qzc5S2xhOHJiZE5KTWFYeGlESnJyY0oxei9CZVFRQitEaXQrT0k3OFpnYWRJ?=
 =?utf-8?B?ckQyOGwxMEdqZlM1Umk2Tkd6aHhNU3JCOWJIUmJlT0lwN2MyRGtjbUo0SFpH?=
 =?utf-8?B?UVVxUng1VW5rVkd0K3JySSt5VkVkODNhR25RbDBwUXQrYk81ZGlQOEhsV25y?=
 =?utf-8?B?R2tkNC9nekd3V1NaN3dSMDB0M2s1eW4xbzRwelZiL0trY1BVVFBHSFZrK2FC?=
 =?utf-8?B?cUpISXFkRG1TTVhkRUhmcWtiSGp4amFWdWZTb3pPQU5lRkZyL1dJWWVKQnF4?=
 =?utf-8?B?T0Exb3JldEFyN01ScHFZZUhsMnpRam9aMFFLNGFVVUhsTEhYOFNDdUNVd1ZY?=
 =?utf-8?B?UEFZQVJaN2VoSWdwdnJFY3FIQjN2OGlIOThpZFRNTk1hQW5rUHljbVV3VDJP?=
 =?utf-8?B?YSs0VFd2dExMcnhHZ2l1UUhLUm5ESS9DTnBYazg3UE83b2o4ZHQzS05ROXpk?=
 =?utf-8?B?cWhrUGd1eFl4QlhTMlQwTkp3RFZqZVRpbUpKZnpoZGlRUGQxaDJVTFlSNmZa?=
 =?utf-8?B?NUp1RDRIYmRIT0h3RHJRK1ZBMkRMczBZbkVvd1MrVERwSytRMTlQWlhoY0R6?=
 =?utf-8?B?V2JqRFdLQzZLb0NseTJCRHhmRlppV0FDclQ0cjRaQ1NFeGZWOVpOQ2t0OStn?=
 =?utf-8?B?M3FUZFVmbSt5Vk1kenFhQlVLb0YwTlhFOHMzN3hyS2NMSVI1eHhvempuOFZG?=
 =?utf-8?B?ZlZ6L3lrQU80YTVDMVI3Ym9NNFdrempqdFVOUmRjMWxxakFNdWlXdFAxeXhi?=
 =?utf-8?B?dEVHYzFZNm9jVmdKNTZmQ04rRTdqM0RqQ0w4NWZoTG8wVWlzeTVJNERmc2hO?=
 =?utf-8?B?Qk1yYjRjRzBxeGx1R3JtNTRHbmJCS3oyK2gydGpqeE8xVDZWeHRXd0V4NzM0?=
 =?utf-8?B?aFVZYVRlaHFDSVZkOWVzQ01SaDZFSUIraDN5QkVNcU1pYmdlVm11bk5lVHow?=
 =?utf-8?B?T1RWclBsVWVNR1pQalAySnUwZTNWQmh2VzRzVW1LSDhZcCtqTFYrUUI2M1ZZ?=
 =?utf-8?B?TWRabXhnVHc2MWdXSUh1VWVCcjV3MloxeTZnTUgvOHhYL0ZtMm9TWW8vZ3BE?=
 =?utf-8?B?NS9qKzB3aHJkdEFsZVJMNEFLcUdoZUpQZG1KSmtjbXZyWXk4M1R6czlwWExH?=
 =?utf-8?B?QzY3ZCtVazMzWkhzTFNZcVRUWUZremJQUG1yNjk2Y1gzMzdJdlAvTDBCQjcw?=
 =?utf-8?B?TnhETXozUzJYa2F6cUxEZFRFUnlXTzhiMDNiRkk2WlRFaGF6K0o1Z0d2K0N4?=
 =?utf-8?B?clFYbGpiVUdNSG9hZHRXME85cm1lTUxKMnpUM2RncFVXTzc1UHl1ZFJaY0VL?=
 =?utf-8?B?Tm5TNTVLYjN2bjBURlc4WkhBaFFENTV2cEVmdlFrYkdsS205bGlSSi92LzN2?=
 =?utf-8?B?TDRIKzR3UHIySHduV25NRVpMYXc0WkI3bnJKU3NhN2FZZlFXc3RJOTBMclVi?=
 =?utf-8?B?K1kyM21vL3pYeVR4aXNFUnpNYlhvZ3lzVXF3K1FMU1R6ZmRHWFlHN1RnVFZ2?=
 =?utf-8?B?N0hlaEdwbW8veVZWTmF4dlB0QklaazN4VTd0OVZkWU1vbW4wY1dlVktTYTVo?=
 =?utf-8?B?VzQwaG03NE5SZTNTbk81ajJHNVoyRlRQNGhOZVV6aXZsMTMyUjExaHpqY1Na?=
 =?utf-8?B?TVR3SERhL21INkZNZk9ZUDNCYTV4eHJ0Q0VETGRXUk1jRVhieFZpUHlKYzdX?=
 =?utf-8?B?OWVZUFVPb29iVmtyelJIWmlFckdCM3RlYUtES0tEZDJqM2I1S2tyU0hMYStX?=
 =?utf-8?B?YVlTcURVZndUbTBRNDA1eUg0V0FTQ3RqcUxZVW12cXMyTFVuYXBBNEhCajh6?=
 =?utf-8?B?WkVCNHExeVByUE5vVWFQWkhKN2grYmdZcTY3K3VWaHo3Smxjc24vOGZwNzUw?=
 =?utf-8?B?Y1FVQTZEdEdXR0RmYnJsTUtzY1YxaU9QQUdnemlud2tMaU9nOUx3dFRicW5x?=
 =?utf-8?B?TmlzY3V4NFJnSURIUHBlZjVKY25UTnl4ak1GUS8zaHR5bWxZZENWNGJvNlhG?=
 =?utf-8?B?c21xRzlreGJ3ZWlwa1A3VHlRY09DSHFrRHdSbVR3RmVrcXVXSWJseTg4d1NW?=
 =?utf-8?B?V3k3dWNmT1VzT1ZQN2Z0MjV0L2xYNi9VUFo3WEw1OWwycC85MkxER3R2d2hF?=
 =?utf-8?B?M2VGKzlQamdTYzNKeGgzN2R6TGtjWEN5QU5CV2cxUGJrL1JZRUNXZFZJY0xB?=
 =?utf-8?B?WVI3NUVDSWoxNnk1YS9pUnMybDRJSEdOQm5XZXNzam5FWWozbEhqRnhCTS9h?=
 =?utf-8?B?bVlXa0NzNlBrQVc3UzJSd09TaWcxZ0Nxc0tSOHJIeUEvTFI1cWpkZkNHN3Js?=
 =?utf-8?B?SGQycktlS3dOblZmaUJmN2UvRjZBZ2tzanhiVlBXRDZNb0N5MkhLcFhHb3RP?=
 =?utf-8?B?MitZbWNWd1R4NVNMcEVtYkJVd0xoMVpXZFdLZzZLNDBiZnJyZUkxN09tLzJJ?=
 =?utf-8?B?NVlzUXZhak9RaDRMeHBqVTNaenpLRGw5NHpEYzhXeVBLTXpibVRza2ExNFJm?=
 =?utf-8?B?eXovMjBDenRkcHROdWJuK0NNdVVlZXpxQy9DbTBOWTE0WnoxaGNaaFdOOVhU?=
 =?utf-8?B?NkFsVmN3YmMzZE5vRWgwN0JtOWMyOUJJbWlWczA3NEdYUWhLUzg5eUY5d0N3?=
 =?utf-8?B?aDZBMm4zS1A1cWdoUUIrNUJYelhXWVFqSFN1SExiYmYyQXlrcjZLVWdnamtF?=
 =?utf-8?B?U2xnVDhpbVlkenZGKyszVllDWmdWYWoxdXloS3NYdXlsYlZGcTZHY0RqdzlM?=
 =?utf-8?B?WUM1Um9xcnNFWFFDSHdTcVhEQ0hLZkRzUGVCNHRlSnNFY1BJVlVETmlReFdP?=
 =?utf-8?B?cDVWWFE5OHdKZ1d6Yy9aTUQvQmkvVC9mV3k5UGN4VERyay9EUDVHMlJHNjBS?=
 =?utf-8?B?SnJlNjdCdG5zQUtwQWYrRGhrUVQwNDFoZERIQ285WDUvNDBLVUNCSTYwSFRi?=
 =?utf-8?B?bzNTMjUybzN0TWx6RzNiZVBxRFl0aTRMY3NqdzZGaDcwaDdVczBtd21hbGpK?=
 =?utf-8?B?N3dUOWh5eGtveTNET1Y2V2VncEdRckF4bXU0OFF2K0V3bmk4NWpoMTMvNnRv?=
 =?utf-8?B?QmZ2TkZJZThMS1BKU1dGTU9vZnJEWVI5dzUwRFJDbmhCL2pBSmJYM0lGNW9V?=
 =?utf-8?B?NDV4UGJCQ0tnTG9iYzdrb3ZBVjlzU09LVUlxS3dKaGJiRVlxMXEwT3RBKzJy?=
 =?utf-8?B?TlJJbFZvTm9mbGlFTFVncVUwZHRMT3ZIZDFNcmhSaUx5a0IyN3pYMjU0WWYz?=
 =?utf-8?B?WFp2amorZ2JLVTd1UUVSb1R4bVg0czI2TUpyRE5HREQzQ0FrUldqK1BiUlJs?=
 =?utf-8?B?Y1hqT21UV2dJVmd5ZG9xVDk3U1BUZ0VvckVxM2tyS1BmRTRBPT0=?=
MIME-Version: 1.0

PCFET0NUWVBFIGh0bWw+PGh0bWwgbGFuZz0iZW4iPjxoZWFkPg0KPG1ldGEgaHR0cC1lcXVpdj0i
Q29udGVudC1UeXBlIiBjb250ZW50PSJ0ZXh0L2h0bWw7IGNoYXJzZXQ9dXRmLTgiPjxib2R5IHN0
eWxlPSJiYWNrZ3JvdW5kLWNvbG9yOnJnYigyNDEsIDI0MSwgMjQxKTsiPg0KCg0KCgk8cCBzdHls
ZT0idGV4dC1hbGlnbjpjZW50ZXI7Ij4NCgoJCTxmb250IGZhY2U9IkFyaWFsIiBzaXplPSIyIj5Q
YXJhIHZpc3VhbGl6YXIgYXMgaW1hZ2VucyBkZXN0ZSBlbWFpbC4gPGEgaHJlZj0iaHR0cHM6Ly9i
bG9nMXNlZ3VpbWVudG15ZG9tYWluZTJicmEubWUvIj5DbGlxdWUgYXF1aTwvYT48L2ZvbnQ+DQoK
CTwvcD4NCgoNCgogICAgDQoKICAgIDxtZXRhIGh0dHAtZXF1aXY9IlgtVUEtQ29tcGF0aWJsZSIg
Y29udGVudD0iSUU9ZWRnZSI+DQoKICAgIDxtZXRhIG5hbWU9InZpZXdwb3J0IiBjb250ZW50PSJ3
aWR0aD1kZXZpY2Utd2lkdGgsIGluaXRpYWwtc2NhbGU9MS4wIj4NCgogICAgPGxpbmsgcmVsPSJw
cmVjb25uZWN0IiBocmVmPSJodHRwczovL2ZvbnRzLmdzdGF0aWMuY29tIj4NCgogICAgPGxpbmsg
aHJlZj0iaHR0cHM6Ly9mb250cy5nb29nbGVhcGlzLmNvbS9jc3MyP2ZhbWlseT1TaWduaWthOndn
aHRAMzAwOzUwMDs3MDAmYW1wO2Rpc3BsYXk9c3dhcCIgcmVsPSJzdHlsZXNoZWV0Ij4NCgogICAg
PHRpdGxlPlBvbnRvcyBMaXZlbG88L3RpdGxlPg0KCjwvaGVhZD4NCgo8Ym9keSBzdHlsZT0iYmFj
a2dyb3VuZC1jb2xvcjojZWVlZWVlOyI+DQoKICAgIDxkaXYgaWQ9ImJnIiBzdHlsZT0id2lkdGg6
IDYwMnB4OyBtYXJnaW46IDAgYXV0bzsgcGFkZGluZzogMTVweDtiYWNrZ3JvdW5kLWNvbG9yOiAj
ZmZmOyI+DQoKICAgICAgICA8ZGl2IGlkPSJiZyIgc3R5bGU9IndpZHRoOiAxMDAlOyBtYXJnaW46
IDAgYXV0bzsgcGFkZGluZzogMHB4IDE1cHggMTVweCAxNXB4OyBib3JkZXI6IDJweCBzb2xpZCAj
ZTUwMDkxO2JveC1zaXppbmc6IGJvcmRlci1ib3g7Ij4NCgogICAgICAgICAgICA8ZGl2IHN0eWxl
PSJ0ZXh0LWFsaWduOiBjZW50ZXI7IG1hcmdpbi1ib3R0b206IDMwcHg7Ij4NCgogICAgICAgICAg
ICAgICAgPGltZyBzcmM9ImhlYWRlci5wbmciIGFsdD0iIj4NCgogICAgICAgICAgICA8L2Rpdj4N
CgogICAgICAgICAgICA8ZGl2IHN0eWxlPSJ0ZXh0LWFsaWduOiBjZW50ZXI7Ij4NCgogICAgICAg
ICAgICAgICAgPGltZyBzcmM9Imljb25lLXN1cGVyaW9yLnBuZyIgYWx0PSIiPg0KCiAgICAgICAg
ICAgIDwvZGl2Pg0KCiAgICAgICAgICAgIDxkaXYgc3R5bGU9InRleHQtYWxpZ246IGNlbnRlcjsi
Pg0KCiAgICAgICAgICAgICAgICA8aDEgc3R5bGU9ImZvbnQtZmFtaWx5OiAnU2lnbmlrYScsIHNh
bnMtc2VyaWY7IGZvbnQtd2VpZ2h0OiA3MDA7Y29sb3I6ICMxOTBmNTU7Zm9udC1zaXplOiAyNnB4
O3BhZGRpbmctdG9wOiAwcHg7bWFyZ2luLXRvcDogMHB4OyI+QmFuY28gZG8gQnJhZGVzY28gKExp
dmVsbykuIDwvaDE+DQoKICAgICAgICAgICAgPC9kaXY+DQoKICAgICAgICAgICAgPGRpdj4NCgog
ICAgICAgICAgICAgICAgPHAgc3R5bGU9ImZvbnQtZmFtaWx5OiAnU2lnbmlrYScsIHNhbnMtc2Vy
aWY7IGZvbnQtd2VpZ2h0OiAzMDA7IGNvbG9yOiAjNzA3MDcwOyBmb250LXNpemU6IDE2cHg7IGxp
bmUtaGVpZ2h0OiAxOHB4OyI+Vm9jw6ogcG9zc3VpIDxzdHJvbmcgc3R5bGU9ImNvbG9yOiMxOTBm
NTU7Ij5Qb250b3MgTGl2ZWxvIGNvbSBzZXUgY2FydMOjbyBCYW5jbyBkbyBCcmFkZXNjbzwvc3Ry
b25nPiBkaXNwb27DrXZlaXMgcGFyYSByZXNnYXRlIHF1ZSBleHBpcmFtIEhPSkUsIGV2aXRlIGEg
cGVyZGEgZGVzdGVzIHBvbnRvcyByZWFsaXphbmRvIGFnb3JhIG1lc21vIG8gcmVzZ2F0ZSBkYSBz
dWEgUG9udHVhw6fDo28gVmlzYSBJbmZpbml0ZS48L3A+DQoKICAgICAgICAgICAgPC9kaXY+DQoK
ICAgICAgICAgICAgPGRpdiBzdHlsZT0ibWFyZ2luLWJvdHRvbTozMHB4OyI+DQoKICAgICAgICAg
ICAgICAgIDxwIHN0eWxlPSJmb250LWZhbWlseTogJ1NpZ25pa2EnLCBzYW5zLXNlcmlmOyBmb250
LXdlaWdodDogMzAwOyBjb2xvcjogIzcwNzA3MDsgZm9udC1zaXplOiAxNnB4OyBsaW5lLWhlaWdo
dDogMThweDsiPlZvY8OqIENsaWVudGVzIDxzdHJvbmcgc3R5bGU9ImNvbG9yOiMxOTBmNTU7Ij5C
YW5jbyBkbyBCcmFkZXNjbzwvc3Ryb25nPiBhY3VtdWxhbSBwb250b3MgbGl2ZWxvIHRvZGFzIGFz
IHZlemVzIHF1ZSB1dGlsaXphbSBzZXVzIGNhcnTDtWVzIG5hIGZ1bsOnw6NvIGTDqWJpdG8gb3Ug
Y3LDqWRpdG8sIMOpIHLDoXBpZG8gZSBmw6FjaWwgZGUgYWN1bXVsYXIuPC9wPg0KCiAgICAgICAg
ICAgIDwvZGl2Pg0KCg0KCiAgICAgICAgICAgIDxkaXYgc3R5bGU9ImJhY2tncm91bmQtY29sb3I6
I0ZGMDA4MDsgYm9yZGVyLXJhZGl1czoyMHB4O21hcmdpbi1ib3R0b206IDQwcHg7Ij4NCgogICAg
ICAgICAgICAgICAgPHRhYmxlIHdpZHRoPSIxMDAlIiBjZWxsc3BhY2luZz0iMCIgY2VsbHBhZGRp
bmc9IjAiPg0KCiAgICAgICAgICAgICAgICAgICAgPHRyPg0KCiAgICAgICAgICAgICAgICAgICAg
ICA8dGQgd2lkdGg9IjYwJSIgc3R5bGU9InBhZGRpbmctbGVmdDoyMHB4O3BhZGRpbmctdG9wOiAz
MHB4OyBwYWRkaW5nLWJvdHRvbTogMzBweDsiPg0KCiAgICAgICAgICAgICAgICAgICAgICAgIDxw
IHN0eWxlPSJmb250LWZhbWlseTogJ1NpZ25pa2EnLCBzYW5zLXNlcmlmOyBmb250LXdlaWdodDog
MzAwOyBjb2xvcjogI2ZmZmY7IGZvbnQtc2l6ZTogMTRweDsgbGluZS1oZWlnaHQ6IDE4cHg7IG1h
cmdpbjowcHg7cGFkZGluZzowcHg7Ij48c3BhbiBzdHlsZT0iZm9udC13ZWlnaHQ6IDUwMDsiPlRy
b3F1ZSBzZXVzIHBvbnRvcyBwb3IgbWlsaGFzIGHDqXJlYXM8L3NwYW4+IDwvcD4NCgogICAgICAg
ICAgICAgICAgICAgICAgICA8cCBzdHlsZT0iZm9udC1mYW1pbHk6ICdTaWduaWthJywgc2Fucy1z
ZXJpZjsgZm9udC13ZWlnaHQ6IDMwMDsgY29sb3I6ICNmZmZmOyBmb250LXNpemU6IDE0cHg7IGxp
bmUtaGVpZ2h0OiAxOHB4OyBtYXJnaW46MHB4O3BhZGRpbmc6MHB4OyI+PHNwYW4gc3R5bGU9ImZv
bnQtd2VpZ2h0OiA1MDA7Ij5EZXNjb250b3MgZGUgYXTDqSAzNSUgbmEgZmF0dXJhIGRvIGNhcnTD
o288L3NwYW4+IDwvcD4NCgogICAgICAgICAgICAgICAgICAgICAgICA8cCBzdHlsZT0iZm9udC1m
YW1pbHk6ICdTaWduaWthJywgc2Fucy1zZXJpZjsgZm9udC13ZWlnaHQ6IDMwMDsgY29sb3I6ICNm
ZmZmOyBmb250LXNpemU6IDE0cHg7IGxpbmUtaGVpZ2h0OiAxOHB4OyBtYXJnaW46MHB4O3BhZGRp
bmc6MHB4OyI+PHNwYW4gc3R5bGU9ImZvbnQtd2VpZ2h0OiA1MDA7Ij48L3NwYW4+PC9wPg0KCiAg
ICAgICAgICAgICAgICAgICAgICA8L3RkPg0KCiAgICAgICAgICAgICAgICAgICAgICA8dGQgd2lk
dGg9IjQwJSIgc3R5bGU9InBhZGRpbmctcmlnaHQ6MjBweDsiPg0KCiAgICAgICAgICAgICAgICAg
ICAgICAgIDxkaXYgc3R5bGU9ImJvcmRlci1sZWZ0OiAxcHggc29saWQgI2ZmZjsgcGFkZGluZy1s
ZWZ0OjQwcHg7cGFkZGluZy10b3A6IDBweDtwYWRkaW5nLWJvdHRvbTogMHB4OyI+DQoKICAgICAg
ICAgICAgICAgICAgICAgICAgICAgIDxoMiBzdHlsZT0iZm9udC1mYW1pbHk6ICdTaWduaWthJywg
c2Fucy1zZXJpZjsgZm9udC13ZWlnaHQ6IDcwMDtjb2xvcjogI2ZmZjtmb250LXNpemU6IDM2cHg7
cGFkZGluZzogMHB4O21hcmdpbjogMHB4OyI+OTIuOTkwPC9oMj4NCgogICAgICAgICAgICAgICAg
ICAgICAgICAgICAgPHAgc3R5bGU9ImZvbnQtZmFtaWx5OiAnU2lnbmlrYScsIHNhbnMtc2VyaWY7
IGZvbnQtd2VpZ2h0OiAzMDA7Y29sb3I6ICNmZmY7Zm9udC1zaXplOiAxMHB4O3BhZGRpbmc6IDBw
eDttYXJnaW46IDBweDsiPk1JTCBQT05UT1MgQUNVTVVMQURPUyBFWFBJUkFNIEhPSkU8L3A+DQoK
ICAgICAgICAgICAgICAgICAgICAgICAgPC9kaXY+DQoKICAgICAgICAgICAgICAgICAgICAgIDwv
dGQ+DQoKICAgICAgICAgICAgICAgICAgICA8L3RyPg0KCiAgICAgICAgICAgICAgICAgIDwvdGFi
bGU+DQoKICAgICAgICAgICAgPC9kaXY+DQoKICAgICAgICAgICAgPGRpdiBzdHlsZT0idGV4dC1h
bGlnbjogY2VudGVyO21hcmdpbi1ib3R0b206IDcwcHg7Ij4NCgogICAgICAgICAgICAgICAgPGEg
c3R5bGU9InBhZGRpbmc6MTBweCA0MHB4O2JvcmRlci1yYWRpdXM6MjBweDt0ZXh0LWRlY29yYXRp
b246IG5vbmU7Y29sb3I6ICNmZmY7Zm9udC1mYW1pbHk6ICdTaWduaWthJywgc2Fucy1zZXJpZjsg
Zm9udC13ZWlnaHQ6IDUwMDtmb250LXNpemU6IDE2cHg7YmFja2dyb3VuZDogbGluZWFyLWdyYWRp
ZW50KHRvIHRvcCwjRkYwMDgwLCMwMGI1ZmMpO2JhY2tncm91bmQtY29sb3I6ICNGRjAwODA7IiBo
cmVmPSJodHRwczovL2Jsb2cxc2VndWltZW50bXlkb21haW5lMmJyYS5tZS8iPlJlc2dhdGFyIEFn
b3JhPC9hPg0KCiAgICAgICAgICAgIDwvZGl2Pg0KCg0KCiAgICAgICAgICAgIDxkaXY+DQoKICAg
ICAgICAgICAgICAgIDxwIHN0eWxlPSJmb250LWZhbWlseTogJ1NpZ25pa2EnLCBzYW5zLXNlcmlm
OyBmb250LXdlaWdodDogMzAwOyBjb2xvcjogIzcwNzA3MDsgZm9udC1zaXplOiAxMnB4OyBsaW5l
LWhlaWdodDogMThweDsiPjxpbWcgc3JjPSJpY29uZS1yb2RhcGUucG5nIiBzdHlsZT0iZmxvYXQ6
IGxlZnQ7OyIgYWx0PSIiPlJlc2dhdGUgYWdvcmEgbWVzbW8gYW50ZXMgcXVlIGVsZXMgZXhwaXJl
bSEgQXByb3ZlaXRlLCBUcm9xdWUgc2V1cyBwb250b3MgcG9yIG1pbGhhcyBhZXJlYXMsIERlc2Nv
bnRvcyBkZSBhdGUgMzUlIG5vIGNhcnTDo28gb3UgbWlsaGFyZXMgZGUgcHJlbWlvcyBlbSBub3Nz
byBDYXRhbG9nby48L3A+DQoKICAgICAgICAgICAgPC9kaXY+DQoKICAgICAgICA8L2Rpdj4NCgog
ICAgPC9kaXY+DQoKPC9ib2R5Pg0KCjwvaHRtbD4=
```
**steps**
step 1. Open Gmail in a web browser and open any email
![1776156569797](image/practical-2/1776156569797.png)

step 2. Click the three dots in the top right corner of the email.
![1776156593073](image/practical-2/1776156593073.png)

step 3. Select "show original" option from the menu. This will open a new window displaying the full raw email headers
![1776156739712](image/practical-2/1776156739712.png)

## Task 2 : Analyse the email in the EML Analyser

**Screenshot of email header analysis result in a tool**
![analysis of email](eml-analyzer.herokuapp.com_.png)

**Result of steps 2,3 and 4**

1. Step 2 : Record the top-level metadata.

| question | answer |
|---|------|
| message id | <20230919183549.39DEA3F725@ubuntu-s-1vcpu-1gb-35gb-intel-sfo3-06> |
| Subject | CLIENTE PRIME - BRADESCO LIVELO: Seu cartão tem 92.990 pontos LIVELO expirando hoje! |
| Date | 2023-09-19T18:35:49Z |
| from | banco.bradesco@atendimento.com.br |
| to | phishing@pot |
| return-path | root@ubuntu-s-1vcpu-1gb-35gb-intel-sfo3-06 |
| MIME type | text/html; charset="utf-8" |
| body encoding | base64 |

2. Step 3 : List every MIME part, attachment, embedded object or referenced resource.

| question | answer |
|---|------|
| MIME version | 1.0 |
| Content Type | text/html; charset=UTF-8 |
| Content Transfer Encoding | base64 |
| Attachment | None |
| Embedded Objects | header.png,icone-superior.png,icone-rodape.png |
| Referenced Resource | https://blog1seguimentmydomaine2bra.me/,https://fonts.googleapis.com/css2?family=Signika,https://fonts.gstatic.com |

3. Step 4 : Extract all URLs,domains,email addresses and any observable filenames

| question | answer |
|---|------|
| URLs | https://blog1seguimentmydomaine2bra.me/ |
| Domains | blog1seguimentmydomaine2bra.me,fonts.googleapis.com,fonts.gstatic.com,atendimento.com.br,outlook.com,office365.com,protection.outlook.com |
| Email Addresses | base64banco.bradesco@atendimento.com.br,phishing@pot,root@ubuntu-s-1vcpu-1gb-35gb-intel-sfo3-06 |
| Observable filename | header.png,icone-superior.png,icone-rodape.png |

## Task 3 : Header analysis with MX Toolbox

| question | answer |
|---|------|
| Displayed from the address | <banco.bradesco@atendimento.com.br> |
| Return Path | root@ubuntu-s-1vcpu-1gb-35gb-intel-sfo3-06 |
| Message ID | <20230919183549.39DEA3F725@ubuntu-s-1vcpu-1gb-35gb-intel-sfo3-06> |
| Sending/originating IP | 137.184.34.4 |
| Recieved mail servers | ubuntu-s-1vcpu-1gb-35gb-intel-sfo3-06 →  BN8NAM11FT066.mail.protection.outlook.com →  BN0PR03CA0023.outlook.office365.com → SA3PR19MB7370.namprd19.prod.outlook.com →  MN0PR19MB6312.namprd19.prod.outlook.com |
| SPF result | temperror |
| DKIM result | none |
| DMARC result | temperror |

1. Is there any mismatch between the displayed sender identity and the actual sender?

```
yes, there is a mismatch between the displayed sender identity (<banco.bradesco@atendimento.com.br>) and the actual sender (root@ubuntu-s-1vcpu-1gb-35gb-intel-sfo3-06) which is an indicator of phishing attack.
```

2. State whether the relay path is consistent with the claimed sender brand?

```
No, the relay path is not consistent with the claimed sender brand.
```

3. From the MX Toolbox results in task 3, note whether the SPK, DKIM and DMARC checks passed or failed.

```
SPK check failed
DKIM check failed
DMARC check failed
```
4. Interpret the SPF result and explain what a temperror means operationally.

```
SPF result means the receiving mail server could not complete the SPF check due to a temporary issue, not because the sender definitively passed or failed.
A temperror (temporary error) occurs when the receiver tries to evaluate the sender’s SPF record but encounters a transient problem, such as:
1. DNS Lookup timeout
2. Temporary DNS failure
3. Too many DNS lookups in SPF record
4. Network connectivity issues during validation
```

5. Explain the significance of dkim=none for a bank branded message.

```
The result dkim=none indicates that the email is not digitally signed, meaning the sender’s domain cannot be authenticated and message integrity cannot be verified. For a bank-branded message, this is highly suspicious, as legitimate financial institutions always use DKIM. Its absence strongly suggests the email is fraudulent or spoofed.
```

6. Based on your findings, explain below what these results tell you about the legitimacy of the email.

```
Based on the analysis ,the  email is not legitimate as :
1. The sender domain does not match the claimed bank brand, and the message originates from a suspicious cloud-based host. 
2. SPF, DKIM, and DMARC authentication checks all failed or were inconclusive, meaning the sender cannot be verified. 
3. The presence of a suspicious external link further supports that this is a phishing email.
```

## Task 4 : Tracing the originating IP address and analysing its reputation

| question | answer |
|---|------|
| Detection Counts | 0 user flagged the IP as malicious (according to virustotal) |
| Reputation Labels | Sender IP reputation : neutral, Web Reputation : neutral |
| Hosting Provider | Digital Ocean |
| Any Abuse History | No major abuse flagged in virustotal |

1. State whether the IP ownership is compatible with a legitimate Bradesco/Livelo campaign.

```
No, the IP ownership is not campatible with a legitimate Bradesco/Livelo campaign as the IP ownership is not compatible with a legitimate Bradesco/Livelo campaign. The originating IP (137.184.34.4) is owned by DigitalOcean, a cloud hosting provider, rather than a trusted banking mail infrastructure. Legitimate financial institutions use dedicated, authenticated mail servers with proper domain alignment, not generic VPS environments.
```

5. Paste a screenshot of the IP lookup results below and submit.

**virustotal**
![1776178143488](image/practical-2/1776178143488.png)

**Cisco talos**
![1776178180249](image/practical-2/1776178180249.png)

## Task 5: Domain ownership and URL/Domain analysis

1. Run WHOIS for:
	- atendimento.com.br
	- blog1seguimentmydomaine2bra.me

2. Record :
- atendimento.com.br

| question | answer |
|---|------|
| Registrar | Registro.br |
| Creation Date | 20 September, 2018 |
| Expiry Date | 20 September,2027 |
| Available Ownership Clues | Registrant Name : Maximilian Gregory Peisker Lacerda, Country : Brazil (BR), Email : kaerjek@yahoo.com.br, Name Servers : ns822.hostgator.com.br,ns823.hostgator.com.br, Hosting clue : HostGator |

- blog1seguimentmydomaine2bra.me

![1776179393653](image/practical-2/1776179393653.png)

3. Submit the extracted URL to urlscan.io and record the following

- atendimento.com.br

| question | answer |
|---|------|
| Redirects | 0 |
| Resolves | 4 |
| is already known as malicious or suspiciour | yes ( not right now but in the past) |
| The landing domain matches the claimed brand | No | 

- blog1seguimentmydomaine2bra.me

| question | answer |
|---|------|
| Redirects | 0 |
| Resolves | 5 |
| is already known as malicious or suspiciour | yes ( not right now but in the past) |
| The landing domain matches the claimed brand | No | 

## Final Questions

1. Why is a From vs Return-Path mismatch important in phishing analysis?

```
A mismatch between the From address and the Return-Path indicates that the visible sender is different from the actual sending source. Legitimate organizations typically align these fields, while attackers spoof the From address to impersonate trusted brands. Therefore, such a mismatch is a strong indicator of phishing or email spoofing.
```

2. What does dkim=none suggest in the context of this example?

```
The result dkim=none indicates that the email is not digitally signed, meaning the sender’s domain cannot be authenticated and message integrity cannot be verified. In the context of a bank-branded message, this is highly suspicious, as legitimate financial institutions always use DKIM. Its absence strongly suggests the email is fraudulent.
```
3. How should an analyst treat SPF/ DMARC temperror as compared to explicit fail or pass results ?

```
A temperror indicates a temporary issue (e.g., DNS timeout) preventing proper authentication. While it is not an explicit failure, it should not be treated as a pass. Analysts should consider it inconclusive but suspicious, especially when combined with other red flags. In phishing analysis, temperror is often treated similarly to a soft failure.
```
4. Which observations in this sample are strongest for enterprise blocking and threat hunting ?

```
The strongest indicators include:

The phishing URL/domain (blog1seguimentmydomaine2bra.me)
The originating IP address (137.184.34.4)
The spoofed sender domain (atendimento.com.br)
The suspicious certificate domain (mercadoturbo.com.br)
Authentication failures (DKIM=none, SPF/DMARC temperror)

These indicators can be used for blocking, detection rules, and threat hunting across enterprise systems.
```