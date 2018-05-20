#include "secure.h"
bool send_mail(const char* to,const char* subject,const char* message)
{
    	bool bError = false;
	try
	{
		CSmtp mail;

#define test_gmail_tls
#if defined(test_gmail_tls)
		mail.SetSMTPServer("smtp.gmail.com",587);
		mail.SetSecurityType(USE_TLS);
#elif defined(test_gmail_ssl)
		mail.SetSMTPServer("smtp.gmail.com",465);
		mail.SetSecurityType(USE_SSL);
#elif defined(test_hotmail_TLS)
		mail.SetSMTPServer("smtp.live.com",25);
		mail.SetSecurityType(USE_TLS);
#elif defined(test_aol_tls)
		mail.SetSMTPServer("smtp.aol.com",587);
		mail.SetSecurityType(USE_TLS);
#elif defined(test_yahoo_ssl)
		mail.SetSMTPServer("plus.smtp.mail.yahoo.com",465);
		mail.SetSecurityType(USE_SSL);
#endif
	
		mail.SetLogin("khachik.khachatryan.s@gmail.com");
		mail.SetPassword("077638605k");
  		mail.SetSenderName("khachik");

  		mail.SetSenderMail("khachik.khachatryan.s@gmail.com");
  		mail.SetReplyTo(to);
  		mail.SetSubject(subject);
  		mail.AddRecipient(to);
  		mail.SetXPriority(XPRIORITY_NORMAL);
  		mail.SetXMailer("Chat FL!(v1.01)Demo");
  		mail.AddMsgLine(message);
		mail.Send();
	}
	catch(ECSmtp e)
	{
        const char* error=(const char*)e.GetErrorText().c_str();
        ERROR_LOGS.insert( pair<const char*,const char*>("send_error",error));
		bError = true;
        return false;
	}
	if(!bError)
    {
		//std::cout << "Mail was send successfully.\n";
        return true;
    }
}
