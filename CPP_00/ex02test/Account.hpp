#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account 
{
public:
	static int	getTotalAmount( void );
	void setTotalAmount(int amount);
private:
	static int	_totalAmount;
};

#endif
