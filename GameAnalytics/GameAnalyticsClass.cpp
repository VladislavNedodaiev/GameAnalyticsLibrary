#include "GameAnalyticsClass.h"

bool GAC::_tofile(const std::string filename, const std::string data) const
{

	std::ofstream ofs(filename);

	if (ofs.is_open())
	{
		ofs << data;
	}

	ofs.close();

	return true;

}

bool GAC::_toserver(const std::string webaddress, const std::string data, const std::string extension) const
{

	// prepare the request
	try
	{
		// you can pass http::InternetProtocol::V6 to Request to make an IPv6 request
		http::Request request(webaddress);

		std::ostringstream stream;
		stream << "data=" << data << "&extension=" << extension;

		// send a post request
		http::Response response = request.send("POST", stream.str(), {
			"Content-Type: application/x-www-form-urlencoded"
			});

		std::cout << std::string(response.body.begin(), response.body.end()) << std::endl; // print the result
	}
	catch (const std::exception& e)
	{
		std::cerr << "Request failed, error: " << e.what() << std::endl;
		return false;
	}

	return true;

	/*// prepare the request
	sf::Http::Request request("postanalytics.php", sf::Http::Request::Post);

	// encode the parameters in the request body
	std::ostringstream stream;
	//stream << "data=" << data << "&extension=" << extension;
	stream << "data=sdsdad&extension=xml";
	request.setBody(stream.str());

	// send the request
	sf::Http http(webaddress);
	sf::Http::Response response = http.sendRequest(request);

	// check the status
	if (response.getStatus() == sf::Http::Response::Ok)
	{
		// check the contents of the response
		return true;
	}
	
	return false;*/

}

std::string GAC::toString() const
{

	int i = 0;
	int count = this->events.size();

	if (count <= 0)
		return "";

	std::string result = "";

	while (i < count - 1)
	{
		result += this->events[i].toString() + "\n";
		i++;
	}

	result += this->events[i].toString();

	return result;

}

std::string GAC::toXML() const
{

	std::string result = "";

	result += "<ArrayOfEvent xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\">";

	int count = this->events.size();
	for (int i = 0; i < count; i++)
	{

		result += this->events[i].toXML();

	}

	result += "</ArrayOfEvent>";

	return result;

}

std::string GAC::toJSON() const
{

	std::string result = "";

	result += "[";

	int i = 0;
	int count = this->events.size();
	while (i < count - 1)
	{
		result += this->events[i].toJSON() + ",";
		i++;
	}
	if (count)
	{
		result += this->events[i].toJSON();
	}


	result += "]";

	return result;

}

std::string GAC::toCSV() const
{

	std::string result = "";

	int i = 0;
	int count = this->events.size();
	while (i < count - 1)
	{
		result += this->events[i].toCSV() + "\n";
		i++;
	}
	if (count)
	{
		result += this->events[i].toCSV();
	}

	return result;

}

std::string GAC::toXML(const std::string path, PostMethod method) const
{

	std::string result = this->toXML();

	if (!method)
		this->_tofile(path, result);
	else
		this->_toserver(path, result, "xml");

	return result;

}

std::string GAC::toJSON(const std::string path, PostMethod method) const
{

	std::string result = this->toJSON();

	if (!method)
		this->_tofile(path, result);
	else
		this->_toserver(path, result, "json");

	return result;

}

std::string GAC::toCSV(const std::string path, PostMethod method) const
{

	std::string result = this->toCSV();

	if (!method)
		this->_tofile(path, result);
	else
		this->_toserver(path, result, "csv");

	return result;

}