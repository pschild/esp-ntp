import groovy.json.JsonSlurper

def jsonSlurper = new JsonSlurper()
URL jsonUrl = new URL("https://gist.githubusercontent.com/pschild/91626aeedd9fbbe66481e05d308793f2/raw/4e6b05ccc24c086089259fa6c2024178d2d29b25/jenkins-esp-environments.json")
def jsonResponse = jsonSlurper.parse(jsonUrl)

def result = []
jsonResponse.each {
    result << it.id + ") " + it.model + " chipId=" + it.chipId
}

return result
