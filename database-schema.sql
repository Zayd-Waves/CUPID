CREATE TABLE IF NOT EXISTS profile (
 id  INTEGER,

 PRIMARY KEY(id ASC)
);

CREATE TABLE IF NOT EXISTS questionnaireAnswer (
 id  INTEGER,
 profileId INTEGER,
 questionNumber INTEGER  NOT NULL,
 ownAnswer1Selected NUMERIC DEFAULT 0,
 ownAnswer2Selected NUMERIC DEFAULT 0,
 ownAnswer3Selected NUMERIC DEFAULT 0,
 ownAnswer4Selected NUMERIC DEFAULT 0,
 groupAnswer1Selected NUMERIC DEFAULT 0,
 groupAnswer2Selected NUMERIC DEFAULT 0,
 groupAnswer3Selected NUMERIC DEFAULT 0,
 groupAnswer4Selected NUMERIC DEFAULT 0,

 PRIMARY KEY(id ASC),
 FOREIGN KEY(profileId) REFERENCES profile(id)
);


CREATE TABLE IF NOT EXISTS student (
   id   INTEGER,
 profileId INTEGER,
   email  TEXT  UNIQUE NOT NULL,
 studentNumber INTEGER  NOT NULL,
 firstName  TEXT  NOT NULL,
 lastName TEXT  NOT NULL,

 PRIMARY KEY(id ASC),
 FOREIGN KEY(profileId) REFERENCES profile(id)
);


CREATE TABLE IF NOT EXISTS algorithmConfig (
 id  INTEGER,
 teamSize INTEGER  DEFAULT 4 CHECK(teamSize > 0),

 PRIMARY KEY(id ASC)
);


CREATE TABLE IF NOT EXISTS administrator (
 id  INTEGER,
 algorithmConfigId INTEGER,
 email  TEXT  UNIQUE NOT NULL,
 firstName TEXT  NOT NULL,
 lastName TEXT  NOT NULL,

 PRIMARY KEY(id ASC),
 FOREIGN KEY(algorithmConfigId) REFERENCES algorithmConfig(id)
);


CREATE TABLE IF NOT EXISTS project (
 id  INTEGER,
 title  TEXT  NOT NULL,
 courseCode TEXT  NOT NULL,
 description TEXT,
 maxNumberRegistrations INTEGER NOT NULL CHECK(maxNumberRegistrations > 0),

 PRIMARY KEY(id ASC)
);


CREATE TABLE IF NOT EXISTS registration (
 id  INTEGER,
 studentId INTEGER,
 projectId INTEGER,
 date  TEXT,
 
 PRIMARY KEY(id ASC),
 FOREIGN KEY(studentId) REFERENCES student(id),
 FOREIGN KEY(projectId) REFERENCES project(id)
);
