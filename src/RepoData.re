type repo = {
  full_name: string,
  stargazers_count: int,
  html_url: string,
};

let parseRepoJson = (json: Js.Json.t) : repo =>
  Json.Decode.{
    full_name: field("full_name", string, json),
    stargazers_count: field("stargazers_count", int, json),
    html_url: field("html_url", string, json),
  };

let parseReposResponseJson = json =>
  Json.Decode.field("items", Json.Decode.array(parseRepoJson), json);

let reposUrl = "https://api.github.com/search/repositories?q=topic%3Areasonml&type=Repositories";
let fetchRepos = () =>
  Bs_fetch.fetch(reposUrl)
  |> Js.Promise.then_(Bs_fetch.Response.text)
  |> Js.Promise.then_(jsonText =>
       Js.Promise.resolve(
         parseReposResponseJson(Js.Json.parseExn(jsonText)),
       )
     );
